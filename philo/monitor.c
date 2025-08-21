/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:57:38 by root              #+#    #+#             */
/*   Updated: 2025/08/21 10:20:48 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void *monitor(void *arg)
//{
//	t_args *data;
//	int	i;

//	data = (t_args *)arg;
//	while (1)
//	{
//		i = 0;
//		while (i < data->philo_count)
//		{
//			pthread_mutex_lock(&data->philo[i].meal_mutex);
//			if (data->philo[i].died)
//			{
//				pthread_mutex_unlock(&data->philo[i].meal_mutex);
//				pthread_mutex_lock(&data->print_mutex);
//				printf("Philosopher %d died\n", data->philo[i].id);
//				pthread_mutex_unlock(&data->print_mutex);
//				return NULL;
//			}
//			pthread_mutex_unlock(&data->philo[i].meal_mutex);
//			i++;
//		}
//		if (all_philos_eaten(data))
//		{
//			pthread_mutex_lock(&data->print_mutex);
//			pthread_mutex_unlock(&data->print_mutex);
//			return NULL;
//		}
//		usleep(1000);
//	}
//	return (NULL);
//}

void	*monitor(void *arg)
{
	t_args *data;
	int	i;
	long	current_time;

	data = (t_args *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->philo[i].meal_mutex);
			current_time = get_current_time();
			if (!data->philo[i].died && (current_time - data->philo[i].last_meal > data->time_to_die))
			{
				pthread_mutex_unlock(&data->philo[i].meal_mutex);
				pthread_mutex_lock(&data->death);
				data->philo[i].died = 1;
				pthread_mutex_unlock(&data->death);
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d died\n", get_relative_time(data), data->philo[i].id);
				pthread_mutex_unlock(&data->print_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philo[i].meal_mutex);
			i++;
		}
		if (data->must_eat_count > 0 && all_philos_eaten(data))
		{
			pthread_mutex_lock(&data->print_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return (NULL);
		}
		usleep(10000);
	}
	return (NULL);
}
