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
}




/*
char *get_next_line(int fd) {
    int bytes_read;
    char *line = NULL;
    size_t len = 0;
    char buffer[BUFFER_SIZE + 1];

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) 
	{
        buffer[bytes_read] = '\0';
        char *temp = realloc(line, len + bytes_read + 1);
        if (!temp) {
            free(line);
            return NULL;
     }
        line = temp;
        strcat(line, buffer);
        len += bytes_read;

        char *newline_pos = strchr(line, '\n');
        if (newline_pos) {
            *newline_pos = '\0';
            return line;
        }
    }

    if (bytes_read == -1) {
        free(line);
        return NULL;
    }
    return line;
}
En este ejemplo, se utiliza la función read() para leer el archivo en bloques de tamaño BUFFER_SIZE, 
y luego se concatenan estos bloques en una sola línea utilizando la función strcat(). 
También se utiliza la función strchr() para buscar un caracter de nue




*/