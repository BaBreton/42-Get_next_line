/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:44:29 by babreton          #+#    #+#             */
/*   Updated: 2023/02/28 08:48:14 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *s);
char	*ft_strndup(char *s, int len);
int     lf_new_line(char *stack);
char    *print_line(char **stack);


#endif