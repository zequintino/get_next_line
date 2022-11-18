/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:46:10 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/18 17:51:41 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	mem_len(char *s, int *nl);
char	*build_line(char *line, char *buf_start, char *buf, int *nl);

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	int		nl;
	ssize_t	rd_len;

	nl = 0;
	line = NULL;
	line = build_line(line, buf, buf, &nl);
	rd_len = read(fd, buf, BUFFER_SIZE);
	while (rd_len > 0 && !nl)
	{
		line = build_line(line, buf, buf, &nl);
		rd_len = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*build_line(char *line, char *buf_start, char *buf, int *nl)
{
	char	*cache;

	free (line);
	cache = (char *)malloc(sizeof(char) * (mem_len(line, nl) + mem_len(buf, nl) + 1));
	if (!cache)
		return (NULL);
	if (line && *line)
		while (*line)
			*cache++ = *line++;
	while (*buf)
	{
		if (*buf == '\n')
		{
			*nl = 1;
			*cache++ = *buf;
			*buf++ = 0;
			*cache = '\0';
			break;
		}
		*cache++ = *buf;
		*buf++ = 0;
	}
	*cache = '\0';
	while (*buf && nl)
	{
		*buf_start++ = *buf;
		*buf++ = 0;
	}
	while (*buf_start)
		*buf_start++ = 0;
	return (cache);
}

ssize_t	mem_len(char *s, int *nl)
{
	ssize_t	len;

	if (!s || !*s)
		return (0);
	len = 0;
	while (*s)
	{
		if (*s == '\n')
		{
			*nl = 1;
			return (len + 1);
		}
		len++;
	}
	return (len);
}

int	main(void)
{
	char	*line = NULL;
	int		fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("\n(after fct call) = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("\n(after fct call) = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("\n(after fct call) = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("\n(after fct call) = %s", line);
	free(line);
}
