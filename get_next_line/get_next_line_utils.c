/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:29 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/24 14:46:31 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i >= start) && (j < len))
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*space;
	unsigned char	*ptr;

	i = nmeb * size;
	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	if (nmeb > INT_MAX / size)
		return (NULL);
	space = malloc(i);
	if (!space)
		return (NULL);
	j = 0;
	ptr = (unsigned char *)space;
	while (j < i)
	{
		ptr[j] = 0;
		j++;
	}
	return (space);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
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

char	*one_line(char *buffer)
{
	int		id;
	char	*c;
	int		i;

	i = 0;
	id = -1;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			id = i;
			break ;
		}
		i++;
	}
	if (id >= 0)
		c = ft_substr(buffer, 0, id + 1);
	else
		c = ft_substr(buffer, 0, ft_strlen(buffer));
	return (c);
}

char	*next_res(char *rest)
{
	char	*new_res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	new_res = NULL;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	len = ft_strlen(rest) - i;
	if (len > 0)
		new_res = ft_calloc(len, 1);
	i++;
	while (i < ft_strlen(rest) && rest[i])
	{
		new_res[j] = rest[i];
		j++;
		i++;
	}
	free(rest);
	return (new_res);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_line;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_line = (char *)malloc(len_s1 + len_s2 + 1);
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, s1, len_s1);
	ft_memcpy(new_line + len_s1, s2, len_s2);
	new_line[len_s1 + len_s2] = '\0';
	return (new_line);
}

char	*add_to_rest(char *rest, char *buffer)
{
	char	*r;

	if (rest == NULL)
	{
		rest = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!rest)
			return (NULL);
	}
	r = ft_strjoin(rest, buffer);
	free(rest);
	rest = r;
	if (!rest)
	{
		free(buffer);
		return (NULL);
	}
	return (rest);
}

char	*read_buffer(int fd, char *rest)
{
	int		bytes_read;
	char	*buffer;

	if (!rest)
		rest = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free(rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = add_to_rest(rest, buffer);
	}
	free (buffer);
	return (rest);
}
