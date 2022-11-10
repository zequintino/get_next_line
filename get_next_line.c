/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/10 17:16:51 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cache_line(char *line, char *buf);

char	*get_next_line(int fd)
{
	ssize_t		r_len;
	static char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			lenght;

	lenght = 3;
	r_len = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE == 0 || r_len <= 0)
		return (NULL);
	cache_line(line, buf);
}

char	*cache_line(char *line, char *buf)
{
	ssize_t		l_len;
	ssize_t		l_feed;
	static char	*cache;

	l_len = 0;
	while (l_len < BUFFER_SIZE)
	{
		if (buf[l_len] == '\n')
		{
			l_feed = l_len;
			break;
		}
		l_len++;
	}










	l_len = 0;
	while ((*line++ = *buf++) && (l_len++ <= l_feed))
		;
}

