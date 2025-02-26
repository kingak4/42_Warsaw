/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:24 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/24 17:25:12 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

char	*read_buffer(int fd, char *rest, int bytes_read);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, void *src, size_t n);
int		ft_strlen(char *s);
char	*add_to_rest(char *rest, char *buffer);
void	*ft_calloc(size_t nmeb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*one_line(char *buffer);
char	*next_res(char *rest);

#endif
