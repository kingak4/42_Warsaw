/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:41:05 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 12:52:51 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//(3 + 1) % 4 = 0
void	init_philo(t_philo *philo, t_args *args, int i)
{
	philo->id = i + 1;
	philo->args = args;
	philo->last_meal = args->time_start;
	philo->eat_count = 0;
	philo->died = 0;
	philo->left_fork = &args->forks[i];
	philo->right_fork = &args->forks[(i + 1) % args->philo_count];
}

void	handle_creation_error(t_philo *philo, t_args *args, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_join(philo[j].thread, NULL);
		j++;
	}
	cleanup(philo, args);
	exit(1);
}

void	start_philo(t_philo *philo, t_args *args)
{
	int	i;
	int	res;

	i = 0;
	args->time_start = get_current_time();
	while (i < args->philo_count)
	{
		init_philo(&philo[i], args, i);
		i++;
	}
	i = 0;
	while (i < args->philo_count)
	{
		res = pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		if (res != 0)
			handle_creation_error(philo, args, i);
		i++;
	}
	i = 0;
	while (i < args->philo_count)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
