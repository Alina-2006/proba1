#include "drawings.h"
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>


void draw_line(BMPFile* bmp, int x0, int y0, int x1, int y1, int thickness, RGB color){
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        for (int t = -thickness / 2; t < (thickness + 1) / 2; t++) {
            for (int s = -thickness / 2; s < (thickness + 1) / 2; s++) {
                int nx = x0 + t;
                int ny = y0 + s;
                if (nx >= 0 && nx < bmp->dhdr.width && ny >= 0 && ny < bmp->dhdr.height) {
                    bmp->data[ny][nx] = color; 
                }
            }
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}


void draw_square(BMPFile* bmp, Square square) {
    if (!bmp ||  square.side_size <= 0 ||  square.thickness <= 0) return;

    int x1 = square.x;
    int y1 = square.y; 
    int x2 = x1 + square.side_size - square.thickness;
    int y2 = y1 + square.side_size - square.thickness;

    if (square.fill) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (x >= 0 && x < bmp->dhdr.width && y >= 0 && y < bmp->dhdr.height) {
                    bmp->data[y][x] = square.fill_color;
                }
            }
        }
    }

    draw_line(bmp, x1, y1, x2, y1, square.thickness, square.color);
    draw_line(bmp, x1, y2, x2, y2, square.thickness, square.color); 
    draw_line(bmp, x1, y1, x1, y2, square.thickness, square.color); 
    draw_line(bmp, x2, y1, x2, y2, square.thickness, square.color); 

    draw_line(bmp, x1, y1, x2, y2, square.thickness, square.color); 
    draw_line(bmp, x1, y2, x2, y1, square.thickness, square.color); 
}
 
void rgb_filter(BMPFile* bmp, const char* component_name, int component_value){
    if (!bmp || !component_name) return;
    
    for (int y = 0; y < bmp->dhdr.height; y++){
        for (int x = 0; x < bmp->dhdr.width; x++){
            if (strcmp(component_name, "red") == 0){
                bmp->data[y][x].r = component_value;
            }
            if (strcmp(component_name, "green") == 0){
                bmp->data[y][x].g = component_value;
            }
            if (strcmp(component_name, "blue") == 0){
                bmp->data[y][x].b = component_value;
            }
        }
    }
}


void turn_image(BMPFile* bmp, int x0, int y0, int x1, int y1, int angle){
    if (x0 < 0 ||  y0 < 0 || x1 >= bmp->dhdr.width ||  y1 >= bmp->dhdr.height ||  x1 < x0 ||  y1 < y0){
        printf("Incorrect area coordinates\n");
        return;
    }
    if (angle != 90 && angle != 180 && angle != 270){
        printf("Invalid rotation angle. Valid values: 90, 180, 270\n");
        return;
    }
    
    int width = x1 - x0 + 1;
    int height = y1 - y0 + 1;
    RGB** temp = (RGB**)malloc(height * sizeof(RGB*));
    for (int y = 0; y < height; y++){
        temp[y] = (RGB*)malloc(width * sizeof(RGB));
    }
    for (int y = y0; y <= y1; y++){
        for (int x = x0; x <= x1; x++){
            temp[y - y0][x - x0] = bmp->data[y][x];
        }
    }

    if (angle == 90){
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                //bmp->data[x0 + x][y1 - y] = temp[y][x];
                bmp->data[y0 + x][y1 - y] = temp[y][x];
            }
        }
    }
    else if (angle == 180){
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                bmp->data[y1 - y][x1 - x] = temp[y][x];
            }
        }
    }
    else if (angle == 270){
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                bmp->data[y1 - x][x0 + y] = temp[y][x];
            }
        }
    }
    for (int y = 0; y < height; y++){
        free(temp[y]);
    }
    free(temp);
}
