/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/12 13:47:46 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	strlen(char *s);
int		check_line_feed(char *line, char *buf);
char *	read_to_line(char *line, int fd);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

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
	}

}




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



