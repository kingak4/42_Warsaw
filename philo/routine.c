/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/22 08:39:03 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (take_forks_right_left(philo));
	else
		return (take_forks_left_right(philo));
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

int	philo_eat(t_philo *philo, t_args *args)
{
	if (philo_take_forks(philo))
		return (1);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_action(philo, "is eating");
	ft_usleep(args->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;
	t_args	*a;

	p = (t_philo *)arg;
	a = p->args;
	if (p->id % 2 != 0)
		ft_usleep(100);
	while (1)
	{
		if (is_any_philo_dead(a) == 1)
			return (NULL);
		if (p->id % 2 == 0)
			usleep(500);
		if (philo_eat(p, a))
			return (NULL);
		if (is_any_philo_dead(a) == 1)
			return (NULL);
		philo_sleep(p);
		philo_think(p);
		if ((a->must_eat_count > 0 && p->eat_count >= a->must_eat_count))
			break ;
		if (is_any_philo_dead(a) == 1)
			return (NULL);
	}
	return (NULL);
}
