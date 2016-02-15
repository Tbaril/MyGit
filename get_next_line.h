#ifndef BUFF_SIZE
# define BUFF_SIZE 6
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int	get_next_line(int const fd, char **line);

#endif
