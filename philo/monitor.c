/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:57:38 by root              #+#    #+#             */
/*   Updated: 2025/08/19 11:43:19 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*monitor(void *args)
//{
//	int		i;
//	long	last_meal_c;
//	t_args	*a = (t_args *)args;

//	// died variable must be defined for each philosopher. If one thread dies, we exit the program. So, I moved the variable died from t_args struct to t_philo struct
//	while (1)
//	{
//		i = 0;
//		while (i < a->philo_count)
//		{
//			pthread_mutex_lock(&a->philo[i].meal_mutex);
//			last_meal_c = get_current_time() - a->philo[i].last_meal;
//			//pthread_mutex_unlock(&a->philo[i].meal_mutex);
//			if (!a->philo[i].died && last_meal_c > a->time_to_die)
//			{
//				a->philo->died = 1;
//				print_action(&a->philo[i], "died");
//				pthread_mutex_unlock(&a->philo[i].meal_mutex);
//				return (NULL);
//			}
//			pthread_mutex_unlock(&a->philo[i].meal_mutex);
//			i++;
//		}
//		ft_usleep(1);
//	}
//	return (NULL);
//}

// void *monitor(void *args)
//{
//     int     i;
//     long    last_meal_c;
//     t_args  *a = (t_args *)args;

//    while (1)
//    {
//        i = 0;
//        while (i < a->philo_count)
//        {
//            pthread_mutex_lock(&a->philo[i].meal_mutex);
//			//printf("last meal philo death time %d %ld\n", a->time_to_die, a->philo[i].last_meal);
//            last_meal_c = get_current_time() - a->philo[i].last_meal;
//			 pthread_mutex_unlock(&a->philo[i].meal_mutex);
//			 pthread_mutex_lock(&a->death);
//            if (last_meal_c > a->time_to_die)
//            {
//                a->philo[i].died = 1;
//                print_action(&a->philo[i], "died");
//               	pthread_mutex_unlock(&a->death);
//                return (NULL);
//            }
//			pthread_mutex_unlock(&a->death);
//            i++;
//        }
//        ft_usleep(1);
//    }
//    return (NULL);
//}
void *monitor(void *arg)
{
	t_args *data = (t_args *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->philo[i].meal_mutex);
			if (data->philo[i].died)
			{
				pthread_mutex_unlock(&data->philo[i].meal_mutex);
				pthread_mutex_lock(&data->print_mutex);
				printf("Philosopher %d died\n", data->philo[i].id);
				pthread_mutex_unlock(&data->print_mutex);
				return NULL;
			}
			pthread_mutex_unlock(&data->philo[i].meal_mutex);
			i++;
		}
		if (all_philos_eaten(data))
		{
			pthread_mutex_lock(&data->print_mutex);
			pthread_mutex_unlock(&data->print_mutex);
			return NULL;
		}
		usleep(1000);
	}
	return (NULL);
}