/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:21 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/18 16:52:48 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*rest;
	char	*r;

	r = read_buffer(buffer , fd, rest);
	
	return (r);

}

int main()
{
	int fd = open("hey.txt", O_RDONLY);
	char *x;
	x = get_next_line(fd);
	printf("%s\n", x);
	x = get_next_line(fd);
	printf("%s", x);
	return (0);
}