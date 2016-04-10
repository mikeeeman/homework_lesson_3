/*
 * copy_file.c
 *
 *  Created on: 10.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	FILE *fpNew, *fpOld;
	int c;


	if(argc != 3)
	{
		fprintf(stderr, "\nArgument type not right!\n");
		return EXIT_FAILURE;
	}

	if((fpOld = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Error during opening source file.\n");
		fclose(fpOld);
		return EXIT_FAILURE;
	}
	if((fpNew = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Error during opening destination file.\n");
		fclose(fpNew);
		return EXIT_FAILURE;
	}

	while(1)
	{
		c = fgetc(fpOld);
		if(!feof(fpOld))
		{
			fputc(c, fpNew);
		}
		else
		{
			break;
		}
	}
	fprintf(stdout, "\nFilename copied from %s to %s", argv[1], argv[2]);

	fclose(fpOld);
	fclose(fpNew);
	return EXIT_SUCCESS;
}

