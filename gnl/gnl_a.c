
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:29 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/13 13:00:40 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if ((!dest) && (!src))
	{
		return (NULL);
	}
	d = (char *) dest;
	s = (char *) src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
		i++;
	return (i);
}
char	add_to_rest(char *rest, char *buffer)
{
	int	len;
	char *new_str;

	len = ft_strlen(buffer) + ft_strlen(rest);




}

int	find_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	if (buffer[0] == '\0')
		return (-1);
	while (buffer[i] != '\n')
		i++;
	return (i);
}
char	*read_buffer(char *buffer, int fd, char *rest)
{
	int	bytes_read;

	bytes_read = 1;
	buffer = calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	//while (bytes_read > 0)
	//{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer 
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
	//}
	buffer[bytes_read] = '\0';
	return (buffer);
}
