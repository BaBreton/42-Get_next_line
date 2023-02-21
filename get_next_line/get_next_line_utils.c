/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:51:07 by babreton          #+#    #+#             */
/*   Updated: 2023/02/21 20:03:49 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int bytes_read)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, bytes_read));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strndup(const char *s, unsigned int size)
{
	char	*array;

	array = (char *)malloc(size * sizeof(char));
	if (!array)
		return (NULL);
	ft_memcpy(array, s, size);
	return (array);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*dp++ = *sp++;
	return (dest);
}

int	ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

/*while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((ft_strchr(buffer, '\n')) == 0) //Navigue dans la string buffer
		{
			if (buffer[search_count] == '\n') //Si le caractere de recherce est /n
			{
				search_count = 0; //On remet le compteur de recherche a zero
				str_count = 0;
				while (buffer[search_count] != '\n') //Donc tant que le caractere est different de /n 
				{
					str[str_count] = buffer[search_count]; //On le copie dans la str
					search_count++; 
					str_count++;
				}
				str[str_count] = '\n';
				return (str);
			}
			else
			{
				buffer = newbuffer(buffer);
			}
			search_count++;
		}
	}*/