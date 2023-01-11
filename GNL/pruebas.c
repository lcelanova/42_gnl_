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
    static char    *buffer;
    char    *line;
    char    *temp;
    int     i;
    int     j;
    int     bytes_read;
    
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    line = (char *)malloc(sizeof(char));
    //line[0] = '\0';
    i = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = malloc(sizeof(char) * (i + bytes_read + 1));
        j = -1;
        while (++j < i)
            temp[j] = line[j];
        j = -1;
        while (buffer[++j])
        {
            if (buffer[j] == '\n')
            {
                temp[i + j] = '\n';
                free(line);
                free(buffer);
                return (temp);
            }
            temp[i + j] = buffer[j];
        }
        i += bytes_read;
        free(line);
        line = temp;
    }
    free(buffer);
    return (line);
}
int main (void)
{
    	int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
} 
