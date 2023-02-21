/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:51:29 by babreton          #+#    #+#             */
/*   Updated: 2023/02/21 20:02:30 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	search_n(const char *temp)
{
	unsigned int	i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	return (i);
}

char	*clear_temp(char *temp)
{
	unsigned int	i;
	unsigned int	j;
	char	*fresh;

	i = 0;
	j = 0;
	while (temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	while (temp[i + j])
	{
		fresh[j] = temp[i + j];
		j++;
	}
	fresh[j] = 0;
	free(temp);
	return (fresh);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*temp = NULL;
	char			*str;
	int				bytes_read; //Stock le nbr de bytes lu par read
	unsigned int	n_count;

	bytes_read = 1;
	n_count = 0;
	if (!fd)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		temp = ft_strjoin(temp, buffer, bytes_read);
		if (ft_strchr(temp, 10) == 1)
		{
			n_count = search_n(temp);
			str = ft_strndup(temp, n_count);
			temp = clear_temp(temp);
			printf("line : ");
			return (str);
		}
	}
	if (str)
		free(str);
	str = NULL;
	return (NULL);
}

int main(void)
{
	int fd = open("fd", O_RDONLY);
	char	*str = NULL;
	// int	i = 0;

	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		// if (i++ == 2)
		// 	return 0;	
	}
	printf("\ntest\n");
	return (0);
}