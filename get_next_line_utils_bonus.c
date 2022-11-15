#include "get_next_line_bonus.h"

ssize_t	check_read(char *str)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);		//increment in order to add the '\\0'
		i++;
	}
	return (i);				//increment in order to add the '\\0'
}

char	*save_to_line(char *line, char *buf, char *cpy_buf, int *check)
{
	char	*tmp;

	int i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (check_read(buf) + check_read(line)) + 1); //add the actual line lenght to the malloc
	while (line && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	while (*buf)
	{
		if(*check)
			*cpy_buf++ = *buf;
		else
			tmp[i++] = *buf;
		*check += (*buf == '\n');
		*buf++ = 0;
	}
	free(line);
	tmp[i] = '\0';
	return (tmp);
}
