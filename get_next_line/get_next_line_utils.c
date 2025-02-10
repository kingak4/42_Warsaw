/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:17 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/10 11:55:55 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	if (buffer[0] == '\0')
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char	*append_to_line(char *line, char *buffer, int newline_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line == NULL)
	{
		line = (char *) malloc(sizeof(*buffer) * (newline_index + 1));
		if (!line)
			return (NULL);
	}
	while (buffer[i] && i < newline_index)
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}
void	shift_buffer(char *buffer, int newline_index)
{
	if (newline_index >= 0 )
		newline_index++;
		while (buffer[newline_index] != '\0')
		{
			buffer[newline_index - 1] = buffer[newline_index];
			newline_index++;
		}
	buffer[newline_index] = '\0';
}
char *handle_eof(char *line, char *buffer)
{
	if (!line)
		return (NULL);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}
int	read_and_store(int fd, char *buffer)
{
	static int	bytes_read;
	static int	new_line;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (-1);
	if (bytes_read == 0)
		return (0);
	buffer[bytes_read] = '\0';
	new_line = find_newline(buffer);
	return (new_line);
}