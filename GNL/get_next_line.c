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
	char		*line_read;
	char		*temp;
	static char	*text;
	char		buffer[BUFFER_SIZE + 1];
	
	bytes_read = 7;
	//system("leaks a.out");
	while (!ft_strchr(text,'\n') && bytes_read > 0)
	{
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(text, buffer);
        free(text);
        text = temp;
	}
	if (bytes_read == -1)
	{
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
		free (text);
		return (NULL);
	}
	ft_strlcpy(line_read, text, i + 1);
	temp = ft_strdup(text + i);
    free(text);
    text = temp;
	return (line_read);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		i = ft_strlen(src);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/* int	main()
{
	int fd;

	fd = open("txt_to_read.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
 */