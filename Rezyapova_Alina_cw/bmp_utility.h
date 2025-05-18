#ifndef BMP_UTIL_H
#define BMP_UTIL_H

#include "bmp_reader.h"
#include "drawings.h"

typedef struct {
    char input_file[256];
    char output_file[256];
    int show_info;
    
    int rotate_mode;
    int rotate_x0, rotate_y0;
    int rotate_x1, rotate_y1;
    int rotate_angle;
    
    int draw_square;
    Square square_params;
    
    int apply_filter;
    char filter_component[16];
    int filter_value;
} ProgramOptions;

void help_info();
void print_bmp_info(BMPFile* bmp);
void parse_options(int argc, char** argv, ProgramOptions* options);

#endif
