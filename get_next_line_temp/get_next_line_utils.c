/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:44:31 by babreton          #+#    #+#             */
/*   Updated: 2023/02/25 15:05:47 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char *s2, char *s1)
{
	char	*str;
	int	i;
	int	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *str)
{
	int		count;
	int 	str_len;
	char	*array;

	count = 0;
	str_len = ft_strlen(str);
	array = (char *)malloc((str_len + 1) * sizeof(char));
	while (str[count] != '\0')
	{
		array[count] = str[count];
		count++;
	}
	array[count++] = '\0';
	return (array);
}
int	have_n(char *str)
{
	int	n;
	int	count;

	n = 10;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == n)
			return (1);
		count++;
	}
	return (0);
}

int	n_loc(char	*str)
{
	int	n;
	int	count;

	n = 10;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == n)
			return (count);
		count++;
	}
	return (count);
}
