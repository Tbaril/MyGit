#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char **ft_realloc(int *s2, int s1, int rd, char **line)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	i = 0;
	while (i < s1)
	{
		tmp[i] = line[i];
		free(line[i]);
		i++;
	}
	free(line);
	line = (char **)malloc(sizeof(char *) * s1);
	i = 0;
	while (i < s1)
	{
		line[i] = (char *)malloc(sizeof(char) * s2[i]);
		line[i] = tmp[i];
		i++;
	}
	line[i] = (char *)malloc(sizeof(char) * rd);
	line[i + 1] = NULL;
	return (line);
}

static void	ft_make_str(int rd, char *buff, char **line)
{
	int			i;
	int			*s2;

	if (!line)
	{
		line = (char **)malloc(sizeof(char *));
		line[0] = (char *)malloc(sizeof(char) * rd);
		line[1] = NULL;
		i = 0;
		while (buff[i] != '\0')
		{
			line[0][i] = buff[i];
			printf("%c\n", line[0][i]);
			i++;
		}
	}
	else
	{
		printf("in\n");
		i = 0;
		while (line[i] != NULL)
		{
			s2[i] = strlen(line[i]);
			i++;
		}
		line = ft_realloc(s2, i, rd, line);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	*tmp = NULL;
	char		buff[BUFF_SIZE + 1];
	int			rd;

	rd = read(fd, buff, BUFF_SIZE);
	buff[rd] = '\0';
	printf("rd = %d\n", rd);
	ft_make_str(rd, buff, line);
	printf("%s\n", line[0]);
	if (rd == 0)
		return(0);
	else if (rd == -1)
		return(-1);
	else
		return (1);
}
