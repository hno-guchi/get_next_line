#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*new_line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			new_line = get_next_line(fd);
			if (new_line == NULL)
				break;
			printf("%s", new_line);
			free(new_line);
		}
	}
	else
	{
		fd = STDOUT_FILENO;
		while (1)
		{
			new_line = get_next_line(fd);
			printf("%s", new_line);
			free(new_line);
		}
	}
	// fsleep(30);
	system("leaks -q a.out");
	return (0);
}
