# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char	buffer[BUFFER_SIZE + 1];
    char	*line;
	int  index_text;
    static char	text[BUFFER_SIZE + 1];
    static int	bytes_read;

	if (text[0])
	{
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
	while (bytes_read = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		
	}

}
int main (void)
{
        int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
}
/*
crear buffer (estatica)
crear linea (temporal)

leo (meto en un buffer) (mientras haya algo que leer)
    meto en otra variable (text)
        compruebo lo que he leido
            hay un salto de linea?
                si 
                    devuelvo hasta el salto de linea, (en una variable linea)
                no
                    es el final del archivo?
                        no
                            sigo leyendo 
        
*/