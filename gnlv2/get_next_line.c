/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:23:34 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/16 12:55:05 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_cache(char *buf, char *line);
ssize_t	s_len(char *s);
char	*clean_buf(char *line, char *buf);


char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rd_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	// line = read_to_cache(buf, 0);
	line = clean_buf(line, buf);
	rd_len = read(fd, buf, BUFFER_SIZE);
	while (rd_len > 0)
	{
		line = read_to_cache(buf, line);
		rd_len = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*clean_buf(char *line, char *buf)
{
	int i;

	i = 0;
	while (*buf != '\n' && *buf)
	{
		*buf = 0;
		buf++;
	}
	*buf = 0;
	buf++;
	while (*buf)
	{
		*line++ = *buf++;
		*buf = 0;
		i++;
	}
	return (&(*(line - i)));
}


char	*read_to_cache(char *buf, char *line)
{
	ssize_t buf_len;
	ssize_t line_len;
	int		i;
	int		k;
	char	*cache;

	if (!*buf)
		return (NULL);
	i = 0;
	buf_len = s_len(buf);
	line_len = s_len(line);
	cache = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	while (*line)
	{
		*cache++ = *line++;
		i++;
	}
	k = i;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			cache[i] = buf[i];
			cache[i + 1] = '\0';
			return (cache);
		}
		cache[i] = buf[i];
		i++;
	}
	if (line)
		free(line);
	return (&(*(cache - k)));
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
