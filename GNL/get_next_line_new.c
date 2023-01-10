#include "get_next_line.h"

char	*get_next_line (int fd)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*text;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free (text);
		return (NULL);
	}
	while (i < BUFFER_SIZE && buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			break;
		i++;
	}
	while (buffer[i] != '\0')
	{
		if()
	}


}

//hola
//ho