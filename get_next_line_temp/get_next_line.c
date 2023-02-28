/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:44:24 by babreton          #+#    #+#             */
/*   Updated: 2023/02/25 15:24:04 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*divider(char *temp, int size)
{
	char	*new_temp;
	int		count;
	int		len;

	if (!temp)
		return (NULL);
	len = ft_strlen(temp) - size;
	new_temp = (char *)malloc((len + 1) * sizeof(char));
	size = size + 1;
	count = 0;
	while (count < len - 1)
	{
		new_temp[count] = temp[size];
		count++;
		size++;
	}
	new_temp[count] = '\0';
	return (new_temp);
}
char	*new_line(char *temp, int size)
{
	char	*return_line;
	int		count;

	if (!temp)
		return (NULL);
	return_line = (char *)malloc((size + 2) * sizeof(char));
	size += 1;
	count = 0;
	while (count < size)
	{
		return_line[count] = temp[count];
		count++;
	}
	return_line[count] = '\0';
	free(temp);
	return (return_line);
}
char	*get_next_line(int fd)
{
	char			*buffer;
	char			*return_line;
	static char		*temp = NULL;
	char			*new_temp;
	int				bytes_read;

	bytes_read = 1;
	if (!fd || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		new_temp = ft_strjoin(buffer, temp);
		temp = new_temp;
		if (have_n(temp) == 1)
			break ;
	}
	if (bytes_read == 0 && ft_strlen(temp) == 0)
	{
    	free(buffer);
    	return (NULL);
	}
	new_temp = divider(temp, n_loc(temp));
	return_line = new_line(temp, n_loc(temp));
	temp = ft_strdup(new_temp);
	free(new_temp);
	free(buffer);
	return (return_line);
}
int main(void)
{
	int fd = open("fd", O_RDONLY);
	char	*str = NULL;
	
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (0);
}