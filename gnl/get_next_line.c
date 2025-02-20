/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:21 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/20 14:23:11 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char *buffer;
	static char	*rest;
	char	*r;
	char *line;
	
	
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	r = read_buffer(buffer , fd, rest);
	line = one_line(r);
	rest = next_res(r);
	return (line);
}

int main()
{
	int fd = open("hey.txt", O_RDONLY);
	char *x;
	x = get_next_line(fd);
	printf("%s", x);
	x = get_next_line(fd);
	printf("%s", x);
	//char *buffer = "hej\nty";
	//printf("%s", one_line(buffer));
	//printf("%s", one_line(buffer));
	return (0);
}