#include "imageRGB.h"
#include "imageGS.h"
#include <stdlib.h>
#include <stdio.h>

MatrixRGB * createMatrixRGB(int rows, int columns)
{
    MatrixRGB *rgb;

    rgb = (MatrixRGB*)malloc(sizeof(MatrixRGB));
    rgb->n = 0;
    rgb->width=rows;
    rgb->height=columns;

    rgb->size = rows*columns;
    
    rgb->data = (ImageRGB *)calloc(rgb->size, sizeof(int));

    return rgb;
}

MatrixRGB * loadFile(char *name)
{

    printf("%s \n", "wow. it got to this point");
    FILE *fp = fopen(name, "rb");

    
    int width, height, max_color;
    char buffer[10];

	fgets(buffer, 10, fp);
	printf("%s \n", buffer);
	fscanf(fp, "%d %d", &width, &height);
	printf("%d %d \n", width, height);
	
    fscanf(fp, "%d", &max_color);
	printf("%d \n", max_color);
    fgets(buffer, 10, fp);
	printf("%s \n", buffer);

    MatrixRGB *rgb = createMatrixRGB(width, height);
    fread(rgb->data, 3 * rgb->width, rgb->height, fp);

    return rgb;
}

void saveFileRGB(MatrixRGB *rgb, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", rgb->width,rgb->height);
    fprintf(fp, "%d\n",255);
    //fwrite(&(rgb->n), sizeof(int), 1, fp);

    fwrite(rgb->data, 3*rgb->width,rgb->height, fp);
}

void color2gray(MatrixRGB *rgb, char *name)
{
    ImageRGB * px = rgb->data;

    MatrixGS * gs = createMatrixGS(rgb->width, rgb->height);
    ImageGS * px2 = gs->data;

    for(int i = 0; i <= gs->size; i++){
        px2->g = px->r * 0.3 + px->g * 0.58 + px->b * 0.11;
        printf("[ %d ]", px2->g);
        
        px++;
        px2++;
    }
    printf("\n");
    saveFileGS(gs, name);
}

void printMatrix(MatrixRGB *rgb)
{

    ImageRGB * px = rgb->data;

    for(int i = 0; i <= rgb->size; i++){
        printf("[ %d, %d, %d ]", px->r, px->g, px->b);
        
        px++;
    }

    printf("\n");
}
