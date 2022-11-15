/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:23:34 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/15 18:48:18 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_line(char *buf, char *line);
ssize_t	pre_lf_len(char *buf);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		r_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_to_line(buf, 0);
	// fct para escrever o buf
	r_len = read(fd, buf, BUFFER_SIZE);
	while (r_len > 0)
	{
		line = read_to_line(buf, line);
	}
	return (line);
}

char	*read_to_line(char *buf, char *line)
{
	ssize_t pre_len;
	int		i;
	char	*cache;

	if (!*buf)
		return (NULL);
	i = 0;
	pre_len = pre_lf_len(buf);
	cache = (char *)malloc(sizeof(char) * (pre_len /* plus line lenght */+ 1));
	// loop struct for saving line content
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
	return (cache);
}

ssize_t	pre_lf_len(char *buf)
{
	ssize_t	len;
	ssize_t	i;

	len = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (len + 1);
		i++;
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
