#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

/**
 * check_type - check type of entry
 *
 * @name: name of entry to check
 *
 * Return: 0 for file 1 for dir
 */
int check_type(char *name)
{
	DIR *directory;
	struct dirent *entry;

	directory = opendir(name);
	if (directory == NULL)
		return (-1);

	entry = readdir(directory);
	if (entry->d_type == DT_REG)
		return (0);
	if (entry->d_type == DT_DIR)
		return (1);
	return (-1);
}
/**
 * check_file - check if all files/directory are accessible
 *
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: nothing
 */
void check_file(int argc, char **argv)
{
	int i;
	DIR *directory;
	struct stat permissions;

	if (argc == 2)
	{
		directory = opendir(argv[1]);
		if (directory == NULL)
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
	}

	else
	{
		for (i = 1; i < argc; i++)
		{
			directory = opendir(argv[i]);
			if (directory == NULL)
			{
				fprintf(stderr, "%s cannot access %s: No such file or directory\n", argv[0], argv[i]);
			}
			stat(argv[i], &permissions);
			if (!(permissions.st_mode & S_IRUSR))
			{
				fprintf(stderr, "%s cannot access %s: Permission denied\n", argv[0], argv[i]);
			}

			closedir(directory);
		}
	}
}

/**
 * hls - print out directory content
 *
 * @dir: name / path of directory
 *
 * Return: nothing
 */
void hls(char *dir)
{
	DIR *directory;
	struct dirent *entry;

	directory = opendir(dir);
	
	if (directory != NULL)
	{
		while ((entry = readdir(directory)) != NULL)
        	{
                	if (entry->d_name[0] != '.')
                        	printf("%s  ", entry->d_name);
        	}
        	printf("\n");
	}
	closedir(directory);
}
