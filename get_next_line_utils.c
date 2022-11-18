/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:45 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/18 15:52:45 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_to_line(char *line, char *buf, char *cpy_buf, int *ln_check)
{
	char	*cache;
	int		i;

	cache = (char *)malloc(sizeof(char)
			* ((s_len(buf) + s_len(line)) + 1));
	if (!cache)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		cache[i] = line[i];
		i++;
	}
	while (*buf)
	{
		if (*ln_check > 0)
			*cpy_buf++ = *buf;
		cache[i++] = *buf;
		*ln_check += (*buf == '\n');
		*buf++ = 0;
	}
	free(line);
	cache[i] = '\0';
	return (cache);
}

int	s_len(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			break ;
		i++;
	}
	return (i);
}
