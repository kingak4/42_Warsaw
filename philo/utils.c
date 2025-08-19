/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:59:30 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 11:40:10 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// a change: added a function with more precise result
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
int	is_dead(t_philo *p)
{
    int dead;

    pthread_mutex_lock(&p->args->death);
    dead = p->died;
    pthread_mutex_unlock(&p->args->death);
    return dead;
}
int has_philo_eaten_max(t_args *data, int i)
{
    int result;

    pthread_mutex_lock(&data->philo[i].meal_mutex);
    result = (data->philo[i].eat_count >= data->must_eat_count);
    pthread_mutex_unlock(&data->philo[i].meal_mutex);

    return result;
}

// Sprawdza, czy wszyscy filozofowie zjedli maksymalną liczbę posiłków
int all_philos_eaten(t_args *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        if (!has_philo_eaten_max(data, i))
            return 0;
        i++;
    }
    return 1;
}

// Funkcja do bezpiecznego inkrementowania liczby posiłków filozofa
void increment_meals(t_args *data, int i)
{
    pthread_mutex_lock(&data->philo[i].meal_mutex);
    data->philo[i].eat_count++;
    pthread_mutex_unlock(&data->philo[i].meal_mutex);
}

// Funkcja do sprawdzania, czy któryś filozof umarł
int is_any_philo_dead(t_args *data)
{
    int i;
    int dead = 0;

    i = 0;
    while (i < data->philo_count)
    {
        pthread_mutex_lock(&data->philo[i].meal_mutex);
        if (data->philo[i].died)
            dead = 1;
        pthread_mutex_unlock(&data->philo[i].meal_mutex);

        if (dead)
            return 1;
        i++;
    }
    return 0;
}