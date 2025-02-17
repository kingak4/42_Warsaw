/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:21 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/13 13:23:22 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*rest;
	char	*r;

	r = read_buffer(buffer , fd);
	printf("%s\n", r);
	
	return (NULL);

}
#include <fcntl.h>

int main()
{
	int fd = open("hey.txt", O_RDONLY);
	char *x;
	x = get_next_line(fd);
	return (0);

}