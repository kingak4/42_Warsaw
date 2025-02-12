/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:14 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/12 10:58:13 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
int		find_newline(char *buffer);
char	*add_to_line(char *rest, char *buffer, int newline_index);
void	shift_buffer(char *buffer, int newline_index);
char	*check_rest(char *rest, char *buffer);
char	read_and_store(int fd);


#endif