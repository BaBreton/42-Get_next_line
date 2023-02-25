/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:44:29 by babreton          #+#    #+#             */
/*   Updated: 2023/02/25 15:21:52 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *buffer, char *temp);
int		ft_strlen(char *s);
char	*ft_strdup(char *str);
int		have_n(char *str);
char	*divider(char *temp, int size);
int		n_loc(char	*str);
char	*new_line(char *temp, int size);
char	*ft_lastdup(char *str);


#endif