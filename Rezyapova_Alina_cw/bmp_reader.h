#ifndef BMP_READER_H
#define BMP_READER_H

#pragma pack(push, 1) //выравнивание в 1 байт
typedef struct BMPHeader {
    unsigned char ID[2];
    unsigned int file_size;
    unsigned char unused[4];
    unsigned int pixel_offset;
} BMPHeader;

typedef struct DIBHeader {
  unsigned int header_size;
  unsigned int width;
  unsigned int height;
  unsigned short color_planes;
  unsigned short bits_per_pixel;
  unsigned int comp;
  unsigned int data_size;
  unsigned int pwidth;
  unsigned int pheight;
  unsigned int colors_count;
  unsigned int imp_colors_count;
} DIBHeader;


typedef struct {
  unsigned char b;
  unsigned char g;
  unsigned char r;
} RGB;

typedef struct BMPFile {
    BMPHeader bhdr;
    DIBHeader dhdr;
    RGB** data;
} BMPFile;
#pragma pack(pop)

BMPFile* loadBMPFile(char* fname);
int saveBMPFile(BMPFile* bmp, const char* filename);
void freeBMPFile(BMPFile* bmp_file);

#endif
