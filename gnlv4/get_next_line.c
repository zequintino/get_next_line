/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:05:25 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/18 16:17:08 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	check_len(char *s, int *nl_check);
char	*save_line(char *line, char *buf, int *nl_check);
char	*buf_leftover(char *buf_start, char *buf,
			char *line, int *nl_check);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			nl_check;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nl_check = 0;
	line = NULL;
	line = buf_leftover(buf, buf, line, &nl_check);
	while (nl_check == 0)
	{
		read(fd, buf, BUFFER_SIZE);
		line = save_line(line, buf, &nl_check);
	}
	return (line);
}

char	*buf_leftover(char *buf_start, char *buf,
			char *line, int *nl_check)
{
	int	i;

	if (!*buf)
		return (NULL);
	i = 0;
	while (*buf)
	{
		if (*buf == '\n')
		{
			*buf++ = 0;
			*nl_check = 1;
			break ;
		}
		line[i++] = *buf;
		*buf++ = 0;
	}
	i = 0;
	while (*buf)
		buf_start[i++] = *buf++;
	while (buf_start[i])
		buf_start[i++] = 0;
	return (/* save_line(line, buf_start, nl_check) */line);
}

char	*save_line(char *line, char *buf, int *nl_check)
{
	char	*cache;
	ssize_t	i;
	ssize_t	k;

	if (!*buf)
		return (NULL);
	if (line)
		free (line);
	cache = (char *)malloc(sizeof(char)
			* (check_len(line, nl_check) + check_len(buf, nl_check) + 1));
	if (!cache)
		return (NULL);
	i = 0;
	k = 0;
	while (line && line[k])
	{
		cache[k] = line[k];
		k++;
	}
	while (buf[i])
	{
		cache[i + k] = buf[i];
		i++;
	}
	cache[i + k] = '\0';
	return (cache);
}

ssize_t	check_len(char *s, int *nl_check)
{
	ssize_t	len;

	if (!s || !*s)
		return (0);
	len = -1;
	while (s[++len])
	{
		if (s[len] == '\n')
		{
			*nl_check = 1;
			return (len + 1);
		}
	}
	return (len);
}

// logic case for now "A\nB\nC\n(EOF)" -> "B\nC\n(EOF)" -> "C\n(EOF)" -> BREAK

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
