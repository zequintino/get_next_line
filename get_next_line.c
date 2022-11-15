/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/14 19:15:37 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	//check len of read bytes
	//save from buffer to line?

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
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
	}
	return (line);
}


/* #include <stdio.h>

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
