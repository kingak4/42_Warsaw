/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:46:07 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/21 10:33:21 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *p)
{
	int	dead;

	pthread_mutex_lock(&p->args->death);
	dead = p->died;
	pthread_mutex_unlock(&p->args->death);
	return (dead);
}

int	has_philo_eaten_max(t_args *data, int i)
{
	int	result;

	pthread_mutex_lock(&data->philo[i].meal_mutex);
	result = (data->philo[i].eat_count >= data->must_eat_count);
	pthread_mutex_unlock(&data->philo[i].meal_mutex);
	return (result);
}

int	all_philos_eaten(t_args *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (!has_philo_eaten_max(data, i))
			return (0);
		i++;
	}
	return (1);
}

void	increment_meals(t_args *data, int i)
{
	pthread_mutex_lock(&data->philo[i].meal_mutex);
	data->philo[i].eat_count++;
	pthread_mutex_unlock(&data->philo[i].meal_mutex);
}

int	is_any_philo_dead(t_args *data)
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->death);
		if (data->philo[i].died == 1)
			dead = 1;
		pthread_mutex_unlock(&data->death);
		if (dead == 1)
			return (1);
		i++;
	}
	return (0);
}
