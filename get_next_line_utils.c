/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:45 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/14 19:15:53 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*save_to_line(char *line, char *buf, char *cpy_buf, int *check)
{
	char	*tmp;

	int i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (check_read(buf) + check_read(line) + 1)); //add the actual line lenght to the malloc
	while (line && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	while (*buf)
	{
		if(*check)
			*cpy_buf++ = *buf;
		else
			tmp[i++] = *buf;
		*check += (*buf == '\n');
		*buf++ = 0;
	}
	free(line);
	tmp[i] = '\0';
	return (tmp);
}
