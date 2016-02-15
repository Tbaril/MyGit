#include "get_next_line.h"
#include <sys/stat.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	**line;

	fd = open(argv[1], O_RDONLY, S_IREAD);
	printf("%d\n", fd);
	printf("%d\n", get_next_line(fd, line));
	printf("%s\n", line);
	close(fd);
	return (0);
}
