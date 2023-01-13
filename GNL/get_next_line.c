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
	char		buffer[BUFFER_SIZE + 1];
	static char	*text;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	text = ft_strjoin(text, buffer);
	while (!ft_strchr(text,'\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		text = ft_strjoin(text, buffer);
	}
	if (bytes_read == -1)
	{
		free (buffer);
		free (text);
		return (NULL);
	}
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	line_read = malloc(sizeof(char) * (i + 1));
	if (!line_read)
	{
		free (buffer);
		free (text);
		return (NULL);
	}
	j = 0;
	while(j < i)
	{
		line_read[j] = text[j];
		j++;
	}
	line_read[j] = '\0';
	text += i;
	return (line_read);
}

int main (void)
{
        int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
}
