/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:20:26 by babreton          #+#    #+#             */
/*   Updated: 2023/02/28 08:52:22 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

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

	i = 0;
	j = 0;
	while (str2[i])
		i++;
	while(str1[j])
	{
		str2[i + j] = str1[j];
		j++;
	}
	return(str2);
}

char	*ft_strjoin(char **temp, char *buffer)
{
	int		str_len;
	char	*array;
	char	*str;

	if (!*temp)
		return (*temp = ft_strdup(buffer, ft_strlen(buffer)));
	str = *temp;
	str_len = ft_strlen(str) + ft_strlen(buffer);
	array = (char *)malloc((str_len + 1) * sizeof(char));
	array = ft_loop(*temp, array);
	array = ft_loop(buffer, array);
	array[str_len + 1] = 0;
	free(*temp);
	return (*temp = array);
}

int	have_n(char	**temp)
{
	int		i;
	int		n;
	char	*str;

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
	int		i;
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
