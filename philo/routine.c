/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/09 00:45:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;
	t_args	*a;

	p = (t_philo *)arg;
	a = p->args;
	if (p->id % 2 == 0)
		usleep(1);
	while (1)
	{
		if (a->died)
			break ;
		philo_think(p, a);
		philo_take_forks(p, a);
		philo_eat(p, a);
		philo_sleep(p, a);
		if (a->must_eat_count > 0 && p->eat_count >= a->must_eat_count)
				break ;
	}
}

void	philo_think(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->print_mutex);
	print_action(philo, "is thinking");
	pthread_mutex_unlock(&args->print_mutex);
	usleep(1000);
}

void	philo_take_forks(t_philo *philo, t_args *args)
{
	philo->left_fork = &args->forks[philo->id];
	philo->right_fork = &args->forks[(philo->id + 1) % args->philo_count];
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
}

void	philo_eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_relative_time(args);
	pthread_mutex_unlock(&philo->meal_mutex);
	print_action(philo, "is eating");
	if (args->must_eat_count > 0)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->meal_mutex);
	}
	usleep(args->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo, t_args *args)
{
	print_action(philo, "is sleeping");
	usleep(args->time_to_sleep * 1000);
}
