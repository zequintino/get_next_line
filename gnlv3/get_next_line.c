/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:23:34 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/16 16:39:46 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	s_len(char *s);
char	*check_buf(char *line, char *buf);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rd_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = check_buf(line, buf);
	rd_len = read(fd, buf, BUFFER_SIZE);
	while (rd_len > 0)
	{
		line = read_to_cache(buf, line);
		rd_len = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*check_buf(char *line, char *buf)
{
	int	nl_check;
	int	i;

	if (!*buf)
		return (NULL);
	nl_check = 0;
	while (*buf)
	{
		if (*buf == '\n')
		{
			nl_check = 1;
			buf++;
		}
		*buf++ = 0;
	}
	i = 0;
	while (nl_check && *buf)
	{
		line[i++] = *buf;
		*buf++ = 0;
	}


}





ssize_t	s_len(char *s)
{
	ssize_t	len;

	len = 0;
	while (*s)
	{
		if (*s == '\n')
			return (len + 1);
		s++;
		len++;
	}
	return (len);
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
