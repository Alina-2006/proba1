#ifndef DRAWINGS_H
#define DRAWINGS_H

#include "bmp_reader.h"

typedef struct {
    int x, y;
    int side_size;
    int thickness;
    RGB color;
    int fill;
    RGB fill_color;
} Square;

void draw_square(BMPFile* bmp, Square square);
void rgb_filter(BMPFile* bmp, const char* component_name, int component_value);
void turn_image(BMPFile* bmp, int x0, int y0, int x1, int y1, int angle);

#endif
