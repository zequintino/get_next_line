/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:45 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/15 17:38:48 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_to_line(char *line, char *buf, char *cpy_buf, int *check)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char)
			* ((check_read(buf) + check_read(line)) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	while (*buf)
	{
		if (*check)
			*cpy_buf++ = *buf;
		tmp[i++] = *buf;
		*check += (*buf == '\n');
		*buf++ = 0;
	}
	free(line);
	tmp[i] = '\0';
	return (tmp);
}

int	check_read(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
