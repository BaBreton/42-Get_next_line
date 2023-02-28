/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton < marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:20:26 by babreton          #+#    #+#             */
/*   Updated: 2023/02/27 17:41:20 by babreton         ###   ########.fr       */
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

char	*ft_strjoin(char **temp, char *buffer)
{
	int	i;
	int	j;
	int str_len;
	char	*str;
	char	*str2;

	if (!*temp)
		return(*temp = ft_strdup(buffer));
	i = 0;
	j = 0;
	str2 = *temp;
	str_len = ft_strlen(str2) + ft_strlen(buffer);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (str2[i])
	{
		str[i] = str2[i];
		i++;
	}
	while (buffer[++j])
		str[i + j] = buffer[j];
	str[i + j] = 0;
	free (*temp);
	return (str);
}
