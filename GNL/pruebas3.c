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
    char        buffer[BUFFER_SIZE + 1];
    char        *line;
    static char rest[BUFFER_SIZE + 1];
    int         i;
    int         j;
    int         bytes_read;

    i = 0;
    if (rest[0])
    {
        j = -1;
        while (rest[++j])
            if (rest[j] == '\n')
            {
                //rest[j] = '\0';
                line = malloc(sizeof(char) * (j + 1));
                j = -1;
                while (rest[++j])
                    line[j] = rest[j];
                //line[j] = '\0';
                j++;
                i = -1;
                while (rest[j])
                    rest[++i] = rest[j++];
                //rest[i] = '\0';
                return (line);
            }
        line = malloc(sizeof(char) * (j + 1));
        j = -1;
        while (rest[++j])
            line[j] = rest[j];
        //line[j] = '\0';
        rest[0] = '\0';
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            //buffer[bytes_read] = '\0';
            j = -1;
            while (buffer[++j])
            {
                if (buffer[j] == '\n')
                {
                    //buffer[j] = '\0';
                    line = (char *)malloc(sizeof(char) * (i + j + 1));
                    if (!line)
                        return (NULL);
                    j = -1;
                    while (buffer[++j])
                        line[i + j] = buffer[j];
                    line[i + j] = '\0';
                    j++;
                    i = -1;
                    while (buffer[j])
                        rest[++i] = buffer[j++];
                    rest[i] = '\0';
                    return (line);
                }
            }
            line = (char *)realloc(line, sizeof(char) * (i + bytes_read + 1));
            j = -1;
            while (buffer[++j])
                line[i + j] = buffer[j];
            i += bytes_read;
            line[i] = '\0';
        }
        if (bytes_read == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

int main (void)
{
        int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
}