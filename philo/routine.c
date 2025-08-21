/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/21 10:20:44 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_take_forks(t_philo *philo)
{
	if (philo->left_fork > philo->right_fork)
	{
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
	}
	else
	{
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
	}
	return (0);
}
void philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep);
}

void philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

// int	philo_eat(t_philo *philo, t_args *args)
//{
//	if (philo_take_forks(philo))
//		return (1);
//	print_action(philo, "is eating"); //dodaj flage ze jak je t ni e moze umierac
//	ft_usleep(args->time_to_eat);
//	pthread_mutex_lock(&philo->meal_mutex);
//	philo->last_meal = get_current_time();
//	philo->eat_count++;
//	//printf("%d eating time = %ld\n", philo->id ,philo->last_meal);
//	pthread_mutex_unlock(&philo->meal_mutex);
//	pthread_mutex_unlock(philo->left_fork);
//	pthread_mutex_unlock(philo->right_fork);
//	return (0);
// }
int philo_eat(t_philo *philo, t_args *args)
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

void *philo_routine(void *arg)
{
	t_philo *p = (t_philo *)arg;
	t_args *a = p->args;

	if (p->id % 2 != 0)
		ft_usleep(1);
	while (1)
	{
		if (is_any_philo_dead(a) == 1)
			return (NULL);
		if (philo_eat(p, a))
		{
			// pthread_mutex_unlock(p->left_fork);
			// pthread_mutex_unlock(p->right_fork);
			return (NULL);
		}
		if (is_any_philo_dead(a) == 1)
			return (NULL);
		if ((a->must_eat_count > 0 && p->eat_count >= a->must_eat_count)){
			break;
		}
		philo_sleep(p);
		if (is_any_philo_dead(a) == 1)
			return (NULL);
		philo_think(p);
	}
	return (NULL);
}
