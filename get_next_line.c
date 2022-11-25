/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/25 17:51:59 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			line_found;
	ssize_t		rd_len;

	line_found = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = buf_leftover(0, buf, &line_found);
	if (line_found)
		return (line);
	rd_len = read(fd, buf, BUFFER_SIZE);
	while (rd_len > 0)
	{
		line = save_line(line, buf, buf, &line_found);
		if (line_found)
			break ;
		rd_len = read(fd, buf, BUFFER_SIZE);
	}
	if (rd_len < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
