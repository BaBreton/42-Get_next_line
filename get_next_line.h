/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:46:43 by babreton          #+#    #+#             */
/*   Updated: 2023/02/28 11:57:45 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_loop(char *str1, char *str2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);

#endif