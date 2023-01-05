# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

char	*gnl (int fd)
{
	size_t		buffer_size;
	int			bytes_read;
	int			i;
	int			j;
	char		*text;
	char		*line_read;
	
	buffer_size = 1024;
	text = malloc(buffer_size * sizeof(char));
	if (!text) 
		return (NULL);
	bytes_read = read(fd, text, buffer_size);
	if (bytes_read == -1)
		return (NULL);
	i = 0;
	j = 0;
	while (text[i] != '\n')
			i++;
	i++;
	while (j <= i)
	{
		ft_putchar_fd(text[j], 1);
		j++;
	}
	ft_strlcpy(line_read, text, i);
	return (line_read);
}
int main (void)
{
    	int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s\n", gnl(fd));
}