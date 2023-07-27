#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function/test
 *
 * Return: 0 on success
 */
int main(void)
{
	DIR *directory;
	struct dirent *entry;

	directory = opendir(".");

	if (directory == NULL)
	{
		fprintf(stderr, "Error opening directory\n");
		return (1);
	}

	while ((entry = readdir(directory)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}
	
	if (closedir(directory) == -1)
	{
		fprintf(stderr, "Error closing directory\n");
		return (1);
	}

	return (0);
}
