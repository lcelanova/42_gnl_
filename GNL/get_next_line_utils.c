/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-f <lmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:58:48 by lmunoz-f          #+#    #+#             */
/*   Updated: 2023/01/14 13:01:54 by lmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *) malloc(sizeof (char) * (s1len + s2len + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < s1len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2len)
	{
		str[s1len] = s2[i];
		s1len++;
	}
	str[s1len] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	char			*s2;

	c1 = (unsigned char)c;
	s2 = (char *) s;
	while (*s2 != c1)
	{
		if (*s2 == '\0')
			return (NULL);
		s2++;
	}
	return (s2);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!(copy))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}