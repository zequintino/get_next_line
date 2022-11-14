#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			check;

	check = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		line = buf[fd];
		while (*line)
			*line++ = 0;
		return (NULL);
	}
	line = NULL;
	while (read(fd, buf[fd], BUFFER_SIZE) || *buf[fd] != 0)
	{
			line = save_to_line(line, buf[fd], buf[fd], &check);
			if (check)
				break;
	}
	return (line);
}
