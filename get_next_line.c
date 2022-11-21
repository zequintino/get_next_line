/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/21 00:59:14 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			line_found;
	ssize_t		i;

	i = 0;
	line_found = 0;
	line = NULL;
	if (read(fd, 0, 0) || BUFFER_SIZE < 1)
	{
		while (*buf)
			buf[i++] = 0;
		return (NULL);
	}
	line = buf_leftover(line, buf, &line_found);
	if (line_found)
		return (line);
	while (read(fd, buf, BUFFER_SIZE))
	{
		line = save_line(line, buf, buf, &line_found);
		if (line_found)
			break ;
	}
	return (line);
}

/* int	main(void)
{
	char	*line = NULL;
	int		fd = open("gnl_test", O_RDONLY);

	while((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return 0;
} */
