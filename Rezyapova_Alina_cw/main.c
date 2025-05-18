#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp_utility.h"
#include "bmp_reader.h"
#include "drawings.h"

int main(int argc, char** argv){
    printf("Course work for option 4.12, created by Rezyapova Alina.\n");
    ProgramOptions options;
    memset(&options, 0, sizeof(options));
    parse_options(argc, argv, &options);

    if (strlen(options.input_file) == 0){
        fprintf(stderr, "Error: Input file not specified (use -i)\n");
        return 1;
    }

    BMPFile* bmp = loadBMPFile(options.input_file);
    if (!bmp) {
        fprintf(stderr, "Error loading BMP file\n");
        return 1;
    }

    if (options.draw_square){
        draw_square(bmp, options.square_params);
    }

    if (options.apply_filter){
        rgb_filter(bmp, options.filter_component, options.filter_value);
    }
    
    if (options.rotate_angle != 0){
        turn_image(bmp, options.rotate_x0, options.rotate_y0, options.rotate_x1, options.rotate_y1, options.rotate_angle);
    }

    printf("succsess\n");
    if (!saveBMPFile(bmp, options.output_file)){
        fprintf(stderr, "Error saving file\n");
        freeBMPFile(bmp);
        return 1;
    }

    freeBMPFile(bmp);
    return 0;
}
