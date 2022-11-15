#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*save_to_line(char *line, char *buf, char *cpy_buf, int *check);
ssize_t	check_read(char *str);

#endif
