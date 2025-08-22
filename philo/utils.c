/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:59:30 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/22 08:39:14 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t time_in_ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time_in_ms)
		usleep(500);
	return (0);
}

int	warp(void)
{
	printf("Error\n");
	return (0);
}

void	cleanup(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_count)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	free(args->forks);
	pthread_mutex_destroy(&args->print_mutex);
	pthread_mutex_destroy(&args->death);
	free(philo);
}

int	take_forks_right_left(t_philo *philo)
{
	usleep(500);
	pthread_mutex_lock(philo->right_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	return (0);
}

int	take_forks_left_right(t_philo *philo)
{
	usleep(500);
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	return (0);
}
