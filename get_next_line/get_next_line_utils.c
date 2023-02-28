/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:20:26 by babreton          #+#    #+#             */
/*   Updated: 2023/02/28 10:24:52 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if(!str)
		return (NULL);
	count = 0;
	array = (char *)malloc((len + 1) * sizeof(char));
	while (count < len)
	{
		array[count] = str[count];
		count++;
	}
	array[count++] = '\0';
	return (array);
}

char	*ft_loop(char *str1, char *str2)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	while (str2[i] != '\0')
			i++;
	while(str1[j])
	{
		str2[i] = str1[j];
		i++;
		j++;
	}
	return(str2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len = len + ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	free(s1);
	return (array);
}

int	have_n(char	**temp)
{
	int		i;
	int		n;
	char	*str;

	if (!temp)
		return (0);
	i = 0;
	n = 10;
	str = *temp;
	while(str[i] != 0)
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	if (str[i] == n)
			return (i);
	return (0);
}

char	*print_line(char **temp)
{
	int		n_pos;
	char	*return_line;
	char	*str;

	str = *temp;
	n_pos = have_n(&*temp);
	if (n_pos)
		n_pos += 1;
	else
		n_pos = ft_strlen(str);
	return_line = ft_strdup(str, n_pos);
	*temp = ft_strdup(str + n_pos, ft_strlen(str + n_pos));
	free(str);
	return (return_line);
}
