/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:14 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/10 10:54:21 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

int		find_newline(char *buffer);
char	*append_to_line(char *line, char *buffer, int newline_index);
void	shift_buffer(char *buffer, int newline_index);
char	*handle_eof(char *line, char *buffer);
int		read_and_store(int fd, char *buffer);
char	*get_next_line(int fd);


#endif