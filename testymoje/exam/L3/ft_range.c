/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:04:02 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 10:02:37 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	size = 0;;
	int i = 0;
	int *rest = 0;
	if (start <= end)
		size = end - start + 1;
	if(start > end)
		size = start - end + 1;
	rest = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		rest[i] = start;
		if (start <= end)
		{
			start++;
		}
		else
			start--;
		i++;
	}
	
	return(rest);
	
}
int main()
{
    int start = 12;
    int end = 16;
    int *arr = ft_range(start, end);
	
    if (arr != NULL)
    {
        for (int i = 0; arr[i] != '\0'; i++)  //
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    }
    return 0;
}