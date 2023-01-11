# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line (int fd)
{
	int			bytes_read;
	int			i;
	int			j;
	char		*line_read;
	static char	*text;
	
	if (text == NULL)
		text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text) 
		return (NULL);
	bytes_read = read(fd, text, BUFFER_SIZE);
	if (bytes_read == -1)
			return (NULL);
	i = 0;
	j = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	line_read = malloc(sizeof(char) * (i + 1));
	if (!line_read)
	{
		free (text);
		return (NULL);
	}
	while(j < i)
	{
		line_read[j] = text[j];
		j++;
	}
	text += i;
	return (line_read);
}
