/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:19 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/13 09:47:43 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *rest;
	char *buffer;
	int new_line_id;
	static char *rest;
	
	if (!rest)
		rest = malloc(1);
	//if (rest)
	//{
	//	line = append_to_line(line, buffer, new_line_id);
	//	free(rest);
	//}
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	//line = NULL;
	buffer = read_and_store(fd);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] != '\0')
	{
		new_line_id = find_newline(buffer);
		if (new_line_id >= 0)
		{
			rest = add_to_line(rest, buffer, new_line_id);
			shift_buffer(buffer, new_line_id);
		}
		//else
		//{
		//	rest = add_to_line(rest, buffer, new_line_id);
		//	shift_buffer(buffer, new_line_id);
		//	free(buffer);
		//}
	}
	rest = check_rest(rest, buffer);
	return (rest);
}

#include "fcntl.h"
int main()
{
	int fd = open("hey", O_RDONLY);
	char *x;
	x = get_next_line(fd);
	return (0);
}