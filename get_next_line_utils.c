/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:45 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/20 03:07:44 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_line(char *line, char *new_buf, char *buf, int *line_found)
{
	char	*buf_cache;
	int		i;

	i = 0;
	*line_found = 0;
	buf_cache = (char *)malloc(sizeof(char)
				* (mem_len(line) + mem_len(buf) + 1));
	if (!buf_cache)
		return (NULL);
	while (line && line[i])
	{
		buf_cache[i] = line[i];
		i++;
	}
	free(line);
	while (*buf)
	{
		if (*line_found == 1)
			*new_buf++ = *buf;
		else
			buf_cache[i++] = *buf;
		if (*buf == '\n')
			*line_found = 1;
		*buf++ = 0;
	}
	buf_cache[i] = '\0';
	return (buf_cache);
}

ssize_t	mem_len(char *s)
{
	ssize_t	len;

	if (!s || !*s)
		return (0);
	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}
