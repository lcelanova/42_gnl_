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

# include "get_next_line.h"
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

char    *get_next_line(int fd)
{
	int		bytes_read;
	int		i;
	int		j;
	char	*text;
	char	*next_line;
	
	text = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (text == NULL) 
		return (NULL);
	bytes_read = read(fd, text, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	i = 0;
	j = 0;
	while (text[i] != '\n')
		i++;
	while(i > 0)
	{
		next_line[j] = text[i];
		i--;
		j++;
	}
    return (next_line);
}

int main (void)
{
    	int	fd = open("txt_to_read.txt", O_RDONLY);
        printf("%s", get_next_line(fd));

} 