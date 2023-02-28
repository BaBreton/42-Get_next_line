/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton < marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:46:34 by babreton          #+#    #+#             */
/*   Updated: 2023/02/27 17:25:55 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(fd)
{
    static char		*temp = NULL;
	char			*buffer;
	char			*return_line;
	int				bytes_read;

	if (!fd || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1 ) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		ft_strjoin(&temp, buffer);
	}
	return (0);
}

int main(void)
{
    int     fd;
    char    *line;

    fd = open("fd", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    return 0;
}
