/*
 * rename_file.c
 *
 *  Created on: 10.04.2016
 *      Author: Michael
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);


	if(argc != 3)
	{
		fprintf(stderr, "\nArgument type not right!\n");
		return EXIT_FAILURE;
	}
	printf("%s\n%s\n%s", argv[0], argv[1], argv[2]);
	if(rename(argv[1], argv[2]) == -1)
	{
		fprintf(stderr, "\nFailed to rename file!\n");
		return EXIT_FAILURE;
	}
	fprintf(stdout, "\nFilename changed from %s to %s", argv[1], argv[2]);

	return EXIT_SUCCESS;
}

