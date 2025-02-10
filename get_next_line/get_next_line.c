/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:19 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/10 15:58:49 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			new_line_id;
	
	buffer = malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] != '\0')
	{
		new_line_id = find_newline(buffer);
		if (new_line_id >= 0)
		{
			line = append_to_line(line, buffer, new_line_id);
			shift_buffer(buffer, new_line_id);
			return (line);
		}
		else
		{
			line = append_to_line(line, buffer, new_line_id);
			shift_buffer(buffer, new_line_id);
		}
		while (read_and_store >= 0)
		{
			
		}
		
	}
}
