#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "hls.h"

/**
 * main - main function/test
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		hls(".");
	}
	check_file(argc, argv);
	for (i = 0; i < argc; i++)
	{
		hls(argv[i]);
	}

	return (0);
}
