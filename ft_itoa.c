/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:38:54 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/07 16:48:36 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*safe_malloc(int sign, int len, int n)
{
	char	*result;

	result = malloc(sign + len + 1);
	if (!result)
		return (NULL);
	result[sign + len] = '\0';
	if (n < 0)
		result[0] = '-';
	return (result);
}

void	check_sign(int *sign, int *tmp, int n)
{
	if (n < 0)
	{
		*sign = 1;
		*tmp = -n;
	}
	else
	{
		*tmp = n;
		*sign = 0;
	}
}

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		sign;
	char	*result;

	tmp = n;
	len = 1;
	check_sign(&sign, &tmp, n);
	if (n < 0)
		tmp = -n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	result = safe_malloc(sign, len, n);
	while (len > 0)
	{
		result[len + sign - 1] = tmp % 10 + '0';
		tmp = tmp / 10;
		len--;
	}
	return (result);
}

int	main(void)
{
	int		test_numbers[] = {0, 123, -123, 2147483647, -2147483648};
	int		num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
	char	*converted;
	
	printf("Testing ft_itoa with different integers:\n");
	for (int i = 0; i < num_tests; i++)
	{
		converted = ft_itoa(test_numbers[i]);
		if (converted)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_numbers[i], converted);
			free(converted); // Free the allocated memory
		}
		else
		{
			printf("ft_itoa(%d) failed to allocate memory!\n", test_numbers[i]);
		}
	}

	return (0);
}