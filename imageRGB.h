#ifndef INC_00_IMAGERGB_H
#define INC_00_IMAGERGB_H

typedef struct{
	unsigned char r,g,b;
}ImageRGB;

typedef struct {
    ImageRGB *data;
    int n;
    int width, height;
    int size;
} MatrixRGB;

MatrixRGB * createMatrixRGB(int rows, int columns);

MatrixRGB * loadFile(char *);

void saveFileRGB(MatrixRGB *v, char *name);

void color2gray(MatrixRGB *dm, char *nome);

void printMatrix(MatrixRGB * dm);

#endif //INC_00_IMAGERGB_H
