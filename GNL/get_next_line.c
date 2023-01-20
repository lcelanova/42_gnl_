/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-f <lmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:09:10 by lmunoz-f          #+#    #+#             */
/*   Updated: 2023/01/20 12:29:23 by lmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	int			i;
	char		*line_read;
	static char	*text;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		text = join_and_free(text, buffer, bytes_read);
	}
	if (bytes_read == -1 || !text)
		return (NULL);
	if (text[0] == '\0')
		return (free (text), NULL);
	i = find_n(text);
	line_read = ft_substr(text, 0, i);
	text = copy_and_free(text, i);
	return (line_read);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen)
	{
		str = malloc(sizeof(char));
		if (str != NULL)
			str[0] = '\0';
		return (str);
	}
	if (len > strlen - start)
		len = strlen - start;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

char	*join_and_free(char *text, char *buffer, int bytes_read)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = ft_strjoin(text, buffer);
	free(text);
	text = temp;
	return (text);
}

char	*copy_and_free(char *text, int i)
{
	char	*temp;

	temp = ft_strdup(text + i);
	free(text);
	text = temp;
	return (text);
}

int	find_n(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}
