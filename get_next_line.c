/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/17 01:12:39 by jquintin         ###   ########.fr       */
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
		return (NULL);
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0 || *buf)
	{
		line = save_to_line(line, buf, buf, &check);
		if (check > 0)
			break ;
	}
	return (line);
}

/* int	main(void)
{
	char	*line = NULL;
	int		fd = open("test", O_RDONLY);
	printf("\n(before fct call)\n");
	while ((line = get_next_line(fd)))
	{
		printf("\n(after fct call) = %s", line);
		free(line);
	}
	return 0;
} */
