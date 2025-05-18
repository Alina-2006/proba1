#include <stdio.h>
#include <stdlib.h>
#include "bmp_reader.h"

#ifndef BMP_READER_C
#define BMP_READER_C



BMPFile* loadBMPFile(char* fname){
    FILE* fp = fopen(fname, "r");
    if (!fp){
        printf("Error: Can`t load the file %s\n", fname);
        return NULL;
    }
    BMPFile* bmp_file = (BMPFile*)malloc(sizeof(BMPFile));
    if (!bmp_file) {
        fclose(fp);
        return NULL;
    }
    fread(&bmp_file->bhdr, sizeof(BMPHeader), 1, fp);
    fread(&bmp_file->dhdr, sizeof(DIBHeader), 1, fp);

    if (!(bmp_file->bhdr.ID[0] == 'B' && bmp_file->bhdr.ID[1] == 'M')){
      fclose(fp);
      free(bmp_file);
      printf("Error: Not a BMP file (invalid signature)\n");
      return NULL;
    }

    if (bmp_file->dhdr.bits_per_pixel != 24){
      fclose(fp);
      free(bmp_file);
      printf("Error: Only 24-bit BMP images are supported\n");
      return NULL;
    }

    int width = bmp_file->dhdr.width;
    int height = bmp_file->dhdr.height;
    int row_padding = (4 - (width * 3) % 4) % 4;

    bmp_file->data = (RGB**)malloc(height * sizeof(RGB*));
    if (!bmp_file->data) {
        fclose(fp);
        free(bmp_file);
        return NULL;
    }
    fseek(fp, bmp_file->bhdr.pixel_offset, SEEK_SET);


    unsigned char* row_buffer = (unsigned char*)malloc(width * 3 + row_padding);
    for (int y = 0; y < height; y++){
      bmp_file->data[y] = (RGB*) malloc(width * sizeof(RGB));
      fread(row_buffer, 1, width * 3 + row_padding, fp);
      for (int x = 0; x < width; x++){
        bmp_file->data[y][x].b = row_buffer[x * 3];
        bmp_file->data[y][x].g = row_buffer[x * 3 + 1];
        bmp_file->data[y][x].r = row_buffer[x * 3 + 2]; 
      }
    }
 
    free(row_buffer);
    fclose(fp);
    return bmp_file;
}

int saveBMPFile(BMPFile* bmp, const char* filename){
    if (!bmp || !filename) {
        printf("Error: invalid parameters\n");
        return 0;
    }

    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Error creating file%s\n", filename);
        return 0;
    }

    fwrite(&bmp->bhdr, sizeof(BMPHeader), 1, file);
    fwrite(&bmp->dhdr, sizeof(DIBHeader), 1, file);

    int width = bmp->dhdr.width;
    int height = bmp->dhdr.height;
    int padding = (4 - (width * 3) % 4) % 4; 
    char pad[3] = {0}; 

    for (int y = 0; y < height; y++) {
        fwrite(bmp->data[y], sizeof(RGB), width, file);
        
        if (padding > 0) {
            fwrite(pad, 1, padding, file);
        }
    }

    fclose(file);
    return 1;
}

void freeBMPFile(BMPFile* bmp_file) {
    if (!bmp_file) return;
    
    if (bmp_file->data) {
        for (int y = 0; y < bmp_file->dhdr.height; y++) {
            free(bmp_file->data[y]);
        }
        free(bmp_file->data);
    }
 
    free(bmp_file);
}

#endif
