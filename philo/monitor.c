/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:57:38 by root              #+#    #+#             */
/*   Updated: 2025/08/13 14:59:11 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *args)
{
	int		i;
	long	last_meal_c;
	t_args	*a = (t_args *)args;
	i = 0;
	a->died = 0;
	while (!a->died)
	{
		i = 0;
		while (i < a->philo_count)
		{
			pthread_mutex_lock(&a->philo[i].meal_mutex);
			last_meal_c = get_current_time() - a->philo[i].last_meal;
			pthread_mutex_unlock(&a->philo[i].meal_mutex);
			if (last_meal_c > a->time_to_die)
			{
				a->died = 1;
				print_action(&a->philo[i], "died");
				return (NULL);
			}
			i++;
		}
		usleep(5000);
	}
	return (NULL);
}

