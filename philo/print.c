/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:07:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 12:36:18 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	now;
	long			mi;

	mi = 0;
	gettimeofday(&now, NULL);
	mi = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (mi);
}

long	get_relative_time(t_args *args)
{
	return (get_current_time() - args->time_start);
}

void	print_action(t_philo *philo, char *message)
{
	long	times;

	times = 0;
	pthread_mutex_lock(&philo->args->print_mutex);
	if (philo->died == 1)
	{
		printf("%ld %d %s\n", times, philo->id, message);
		pthread_mutex_unlock(&philo->args->print_mutex);
		return ;
	}
	times = get_relative_time(philo->args);
	printf("%ld %d %s\n", times, philo->id, message);
	pthread_mutex_unlock(&philo->args->print_mutex);
}
//void	print_action(t_philo *philo, char *message) 1
//{
//	long	times;

//	pthread_mutex_lock(&philo->args->print_mutex);
//	times = get_relative_time(philo->args);
//	if (!is_dead(philo))
//		printf("%ld %d %s\n", times, philo->id, message);
//	pthread_mutex_unlock(&philo->args->print_mutex);
//}
//void print_action(t_philo *philo, char *message)
//{
//    long times;

//    pthread_mutex_lock(&philo->args->print_mutex);
//    times = get_relative_time(philo->args);
//    printf("%ld %d %s\n", times, philo->id, message);
//    pthread_mutex_unlock(&philo->args->print_mutex);
//}