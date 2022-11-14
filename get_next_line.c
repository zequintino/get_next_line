/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/14 19:15:37 by jquintin         ###   ########.fr       */
=======
/*   Updated: 2022/11/12 13:47:46 by jquintin         ###   ########.fr       */
>>>>>>> e76a9328d0a10cd02b059990d7dd56e20011049b
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
	//check len of read bytes
	//save from buffer to line?
=======
ssize_t	strlen(char *s);
int		check_line_feed(char *line, char *buf);
char *	read_to_line(char *line, int fd);
>>>>>>> e76a9328d0a10cd02b059990d7dd56e20011049b

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
<<<<<<< HEAD
	int			check;

	check = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		line = buf;
		while (*line)
			*line++ = 0;
		return (NULL);
	}
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0 || *buf != 0)
	{
		line = save_to_line(line, buf, buf, &check);
		if (check)
			break;
=======

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_to_line(line, fd);
	return (line);
}

char *	read_to_line(char *line, int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		rd_len;

	while (read(fd, buf, BUFFER_SIZE) && !check_line_feed(line, fd))
	{
		/* code */
>>>>>>> e76a9328d0a10cd02b059990d7dd56e20011049b
	}
	return (line);
}

}

/* #include <stdio.h>

<<<<<<< HEAD
int	main()
{
	char	*line;
	int fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
} */
=======


int	check_lf(char *line, char *buf)
{

}

ssize_t	strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while(*s++ && len++)
		;
	return (len);
}



>>>>>>> e76a9328d0a10cd02b059990d7dd56e20011049b
