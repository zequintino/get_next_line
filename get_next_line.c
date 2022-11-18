/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:35 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/18 15:47:35 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	//ln_check len of read bytes
	//save from buffer to line?

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			ln_check;

	ln_check = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) && !ln_check)
	{
		line = save_to_line(line, buf, buf, &ln_check);
		if (ln_check)
			break ;
	}
	return (line);
}

int	main(void)
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
}
