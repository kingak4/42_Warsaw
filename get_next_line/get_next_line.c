/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:21 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/24 13:12:02 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char	*r;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	r = read_buffer(fd, rest);
	line = one_line(r);
	rest = next_res(r);
	return (line);
}

//int main()
//{
//	int fd = open("hey.txt", O_RDONLY);
//	char *x;
//	x = get_next_line(fd);
//		printf("%s", x);
//	free(x);
//	x = get_next_line(fd);
//		printf("%s", x);
//		free(x);
//		return (0);
//}