/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:38:56 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/25 17:49:12 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			line_found;
	ssize_t		rd_len;

	line_found = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = buf_leftover(0, buf[fd], &line_found);
	if (line_found)
		return (line);
	rd_len = read(fd, buf[fd], BUFFER_SIZE);
	while (rd_len > 0)
	{
		line = save_line(line, buf[fd], buf[fd], &line_found);
		if (line_found)
			break ;
		rd_len = read(fd, buf[fd], BUFFER_SIZE);
	}
	if (rd_len < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
