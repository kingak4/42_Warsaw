/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:17 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/13 09:43:15 by kikwasni         ###   ########.fr       */
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
	while (s != '\0')
		i++;
	return (i);
}
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
	return (-1); // zoazctmy czy nie damy 0
}
char	*add_to_line(char *rest, char *buffer, int newline_index)
{
	int		len;
	char	*new_str;

	len = ft_strlen(buffer) + ft_strlen(rest);
	if (rest == NULL)
	{
		rest = (char *) malloc(BUFFER_SIZE + 1);
		if (!rest)
			return (NULL);
	}
	new_str = (char *)malloc(rest + 1);
	if (!new_str)
		 return (NULL);
	new_str = ft_memcpy(rest, buffer, len);
	rest[len] = '\0';
	return (rest);
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
char *check_rest(char *rest, char *buffer)
{
	if (!rest)
		return (NULL);
	if (rest[0] == '\0')
		return (NULL);
	return (rest);
}
char	*read_and_store(int fd, char *rest)
{
	int		bytes_read;
	int		new_line;
	char	*buffer;
	
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free (rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';	// po co to ?
		new_line = find_newline(buffer);
		add_to_line(rest, buffer, new_line);
	}
	return (buffer); // a tu nie powinno byc rest xd ?
}
