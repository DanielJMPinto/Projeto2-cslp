#include <stdio.h>
#include "imageRGB.h"
#include "imageGS.h"
#include "imageBi.h"
#include <string.h>
#include <stdlib.h>

/** \mainpage <h1>Image Processing</h1>
 * 
 * This is a simple image manipulation project.
 * 
 * The main purpose of this project is to manipulate images in the pnm format.
 * 
 * Users can:<ul>
 * <li>Convert one format of image into another</li>
 * <li>Apply filters</li>
 * <li>Increse/Decrease intensity of an image</li>
 * </ul>
 * 
 * \authors Rodrigo Oliveira, Daniel Pinto
 */

/**
 * Main program 
 */

int main(int argc, char** argv[])
{	

	char *filename = argv[1];

	MatrixRGB *rgb = loadFileRGB(filename);

    color2gray(rgb, "../res/pgm/salvar_gs.pgm");

	MatrixGS *gs = loadFileGS("../res/pgm/salvar_gs.pgm");

	intensityRGB(rgb, 50, "../res/ppm/intensity_change.ppm");

	intensityGS(gs, 50, "../res/pgm/intensity_change.pgm");

	filterRGB(rgb, "../res/ppm/filter_media.ppm");

	filterGS(gs, "../res/pgm/filter_media.pgm");
	//gray2bin(gs, 70, "../res/pbm/salvar_bin.pgm");

	watermarkRGB(rgb, "../res/ppm/watermarked_rgb.ppm");

	watermarkGS(gs, "../res/pgm/watermarked_gs.pgm");
	
    return 0;
}


