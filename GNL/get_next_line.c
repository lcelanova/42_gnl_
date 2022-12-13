/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-f <lmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:58:44 by lmunoz-f          #+#    #+#             */
/*   Updated: 2022/12/11 23:08:07 by lmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int buffer_size;
	int	bytes_read;
	char	*buffer;
    char	*first_line;
	int	i;
	
	buffer_size = 1024;
	buffer = (char *)malloc(buffer_size * sizeof(char));
	if (buffer == NULL) 
		return (NULL);
	bytes_read = read(fd, buffer, buffer_size);
	i = 0;
	if (bytes_read == -1)
		return (NULL);
	while (i < bytes_read)
	{ 
		if (buffer[i] == '\n') 
        {
			buffer[i] = '\0';
			break ; 
		}
		i++;
    }
    while (*buffer != '\0')
		{
			ft_putchar_fd(*buffer, 1);
            buffer++;
		}
    return (buffer);
}

int main (void)
{
    	int	fd = open("txt_to_read.txt", O_RDONLY);
        char *next_line = get_next_line(fd);
        char *next_line1 = get_next_line(fd);
}