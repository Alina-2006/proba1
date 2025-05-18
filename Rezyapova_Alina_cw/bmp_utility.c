#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "bmp_reader.h"
#include "bmp_utility.h"

void help_info(){
    printf("Edit the BMP image\n");
    printf("Usage: cw  [options] -i input.bmp -o out.bmp\n");
    printf("Options:\n");
    printf("  -h, --help               Show this help message\n");
    printf("  -I, --info FILENAME      Show BMP image information\n");
    printf("  -i, --input FILENAME     Show BMP file information\n");
    printf("  -o, --output FILENAME    Set output filename\n");
    printf("\nRotate:\n");
    printf("  -R, --rotate             Enable rotation\n");
    printf("  -a, --angle ANGLE        Rotation angle (90, 180, 270 degrees)\n");
    printf("  -l, --left_up X.Y        Top-left corner coordinates\n");
    printf("  -r, --right_down X.Y     Bottom-right corner coordinates\n");
    printf("\nSquare with diagonals:\n");
    printf("  -s, --squared_lines      Draw square with diagonals\n");
    printf("  -l, --left_up X.Y        Top-left corner coordinates\n");
    printf("  -S, --side_size N        Square side length (pixels)\n");
    printf("  -t, --thickness N        Line thickness (default: 1)\n");
    printf("  -c, --color R.G.B        Line color (e.g. 255.0.0 for red)\n");
    printf("  -f, --fill               Enable fill (optional)\n");
    printf("  -F, --fill_color R.G.B   Fill color (requires --fill)\n\n");
    printf("\nRGB Filter:\n");
    printf("  -r, --rgbfilter          Apply RGB channel filter\n");
    printf("  -C, --component_name     Channel: red, green or blue\n");
    printf("  -v, --component_value N  New value (0-255)\n\n");
}

void print_bmp_info(BMPFile* bmp){
    printf("BMP File Information:\n");
    printf("  Width: %d Height: %d \n", bmp->dhdr.width, bmp->dhdr.height);
    printf("  Bits per pixel: %d\n", bmp->dhdr.bits_per_pixel);
    printf("  File size: %d\n", bmp->bhdr.file_size);
}

void parse_options(int argc, char** argv, ProgramOptions* options){
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"info", no_argument, 0, 'I'},
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"rotate", no_argument, 0, 'R'},      
        {"left_up", required_argument, 0, 'l'},
        {"right_down", required_argument, 0, 'r'},
        {"angle", required_argument, 0, 'a'}, 
        {"squared_lines", no_argument, 0, 's'},
        {"side_size", required_argument, 0, 'S'},
        {"thickness", required_argument, 0, 't'},
        {"color", required_argument, 0, 'c'},
        {"fill", no_argument, 0, 'f'},
        {"fill_color", required_argument, 0, 'F'},
        {"rgbfilter", no_argument, 0, 'g'},
        {"component_name", required_argument, 0, 'C'},
        {"component_value", required_argument, 0, 'v'},
        {0, 0, 0, 0}
    };
    int opt;
    while ((opt = getopt_long(argc, argv, "hIi:o:Rl:r:a:sS:t:c:fF:gC:v:", long_options, NULL)) != -1){
        switch (opt){
            case 'h': help_info(); exit(0);
            //case 'I': options->show_info = 1; break;
            case 'I':  // Для -I или --info
                options->show_info = 1;
                // Если input_file не указан через -i, используем следующий аргумент как имя файла
                if (strlen(options->input_file) == 0 && optarg) {
                    strncpy(options->input_file, optarg, sizeof(options->input_file));
                }
                break;
            case 'i': strncpy(options->input_file, optarg, sizeof(options->input_file)); break;
            case 'o': strncpy(options->output_file, optarg, sizeof(options->output_file)); break;
            
            case 'R': options->rotate_mode = 1; break;
            case 'l':
                if (options->draw_square) {
                    sscanf(optarg, "%d.%d", &options->square_params.x, &options->square_params.y);
                } else {
                    sscanf(optarg, "%d.%d", &options->rotate_x0, &options->rotate_y0);
                }
                break;
            case 'r': sscanf(optarg, "%d.%d", &options->rotate_x1, &options->rotate_y1); break;
            case 'a': options->rotate_angle = atoi(optarg); break;
            
            case 's': options->draw_square = 1; break;
            case 'S': options->square_params.side_size = atoi(optarg); break;
            case 't': options->square_params.thickness = atoi(optarg); break;
            case 'c': sscanf(optarg, "%hhu.%hhu.%hhu", &options->square_params.color.r, &options->square_params.color.g, &options->square_params.color.b); break;
            case 'f': options->square_params.fill = 1; break;
            case 'F': sscanf(optarg, "%hhu.%hhu.%hhu", &options->square_params.fill_color.r, &options->square_params.fill_color.g, &options->square_params.fill_color.b); break;
            
            case 'g': options->apply_filter = 1; break;
            case 'C': strncpy(options->filter_component, optarg, sizeof(options->filter_component)); break;
            case 'v': options->filter_value = atoi(optarg); break;
            
            default: help_info(); exit(1);
        }
    } 
}
