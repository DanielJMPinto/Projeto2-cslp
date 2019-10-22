#include "imageGS.h"
#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>

MatrixGS * createMatrixGS(int rows, int columns)
{
    MatrixGS *gs;

    gs = (MatrixGS*)malloc(sizeof(MatrixGS));
    gs->n = 0;
    gs->width=rows;
    gs->height=columns;

    gs->size = rows*columns;
    
    gs->data = (ImageGS *)calloc(gs->size, sizeof(int));

    return gs;
}

MatrixGS * loadFileGS(char *name)
{

    //printf("%s \n", "wow. it got to this point");
    FILE *fp = fopen(name, "rb");

    
    int width, height, max_color;
    char buffer[10];

	fgets(buffer, 10, fp);
	//printf("%s \n", buffer);
	fscanf(fp, "%d %d", &width, &height);
	//printf("%d %d \n", width, height);
	
    fscanf(fp, "%d", &max_color);
	//printf("%d \n", max_color);
    fgets(buffer, 10, fp);
	//printf("%s \n", buffer);

    MatrixGS *gs = createMatrixGS(width, height);
    fread(gs->data, 3 * gs->width, gs->height, fp);

    return gs;
}

void saveFileGS(MatrixGS *gs, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", gs->width,gs->height);
    fprintf(fp, "%d\n",255);
    //fwrite(&(gs->n), sizeof(int), 1, fp);

    fwrite(gs->data, 3*gs->width,gs->height, fp);
}

void color2bin(MatrixGS * gs, char * tsh, char * name)
{
    ImageGS * px = gs->data;

    MatrixBi * bi = createMatrixBi(gs->width, gs->height);
    ImageBi * px2 = bi->data;
    int p=0 ,j = 0;
    
    for(int i = 0; i < bi->size; i++){
        
        if(px->g < tsh){
            p++;
            px2->b = 0;
        }else
        {
            j++;
            px2->b = 1;
        }
        
        //printf("[ %d ]", px2->g);
        
        px++;
        px2++;
    }
    int hist[2];
    hist[0]=p;
    hist[1]=j;
    printf("p - %i\nj - %i\nsize - %d\n", p,j, bi->size);
    printf("0 - %i\n1 - %i", hist[0], hist[1]);
    printf("\n");
    saveFileBi(bi, name);
}