/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:44:24 by babreton          #+#    #+#             */
/*   Updated: 2023/02/28 09:23:44 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *print_line(char **stack)
{
	int     i;
	char    *to_print;
	char    *tmp;

	if (!*stack)
		return (NULL);
	i = 0;
	tmp = *stack;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	to_print = ft_strndup(tmp, i);
	*stack = ft_strndup(tmp + i, ft_strlen(tmp + i));
	free(tmp);
	return (to_print);
}

char    *get_next_line(int fd)
{
	static char *stack = NULL;
	char        *str;
	int         b_read;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(stack), stack = NULL, NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, str, BUFFER_SIZE);
		str[b_read] = '\0';
		stack = ft_strjoin(stack, str);
		if (lf_new_line(stack))
			break;
	}
	free(str);
	return (print_line(&stack));
}
/*int main(void)
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
}*/