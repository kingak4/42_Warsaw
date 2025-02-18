/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:24 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/18 16:52:25 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		find_newline(char *buffer);
char	*read_buffer(char *buffer, int fd, char *rest);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, void *src, size_t n);
size_t	ft_strlen(char *s);
char	*add_to_rest(char *rest, char *buffer);
void	*ft_calloc(size_t nmeb, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
