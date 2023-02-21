/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:46:30 by babreton          #+#    #+#             */
/*   Updated: 2023/02/21 19:05:05 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s, unsigned int size);
char	*ft_strjoin(char *s1, char *s2, int bytes_read);
int	ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
unsigned int	search_n(const char *temp);
char	*clear_temp(char *temp);

#endif