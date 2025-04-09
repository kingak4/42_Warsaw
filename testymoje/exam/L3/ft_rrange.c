/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:13:12 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 10:44:29 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int i = 0;
	int size = 0;
	int *rest = 0;
	
	if(end <= start)
		size = start - end + 1;
	if(end > start)
		size = end - start + 1;
	rest = (int *)malloc(size *sizeof(int));
	while (i < size)
	{
		rest[i] = end;
		if(end <= start)
			end++;
		else
			end--;
		i++;
	}
	return(rest);
}

int main()
{
    int start = 10;
    int end = 5;
    
    int *arr = ft_rrange(start, end);
    int size = (start > end) ? (start - end + 1) : (end - start + 1); 
	
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    }
    return 0;
}