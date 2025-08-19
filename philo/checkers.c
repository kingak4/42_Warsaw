/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:33:47 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 10:42:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		return (0);
	if (!str[i])
		return (0);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

int	is_valid_input(char *arg)
{
	if (!is_valid_number(arg) || !is_int_range(arg))
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

int	init_args_struct(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&args->print_mutex, NULL);
	pthread_mutex_init(&args->death, NULL);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_count);
	if (!args->forks)
		return (0);
	while (i < args->philo_count)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	args->philo = malloc(sizeof(t_philo) * args->philo_count);
	if (!args->philo)
		return (0);
	i = 0;
	while (i < args->philo_count)
	{
		pthread_mutex_init(&args->philo[i].meal_mutex, NULL);
		i++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_args *args)
{
	if (ac != 5 && ac != 6)
		return (warp());
	if (ac == 6)
	{
		if (av[6] != NULL || !is_valid_input(av[5]))
			return (0);
	}
	if (!is_valid_input(av[1]) || !is_valid_input(av[2])
		|| !is_valid_input(av[3]) || !is_valid_input(av[4]))
		return (0);
	args->philo_count = ft_atol(av[1]);
	args->time_to_die = ft_atol(av[2]);
	args->time_to_eat = ft_atol(av[3]);
	args->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		args->must_eat_count = ft_atol(av[5]);
	else
		args->must_eat_count = -1;
	if (args->philo_count == 0 || args->time_to_die == 0
		|| args->time_to_sleep == 0 || args->time_to_eat == 0
		|| args->must_eat_count == 0)
		return (warp());
	return (1);
}
