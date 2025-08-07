/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/07 17:19:24 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				eat_count;
	struct s_args	*args;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
}	t_philo;

typedef struct s_args
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	print_mutex;
	long			time_start;
	int				died;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}		t_args;

int		is_valid_number(char *str);
int		is_int_range(char *str);
int		is_valid_input(char *arg);
long	ft_atol(const char *nptr);
void	init_args_struct(t_args *args);
int		parse_args(int ac, char **av, t_args *args);
long	get_current_time(void);
long	get_relative_time(t_args *args);
void	print_action(t_philo *philo, char *message);
int		warp(void);
void	handle_one_philo(t_philo *philo);
void	init_philo(t_philo *philo, t_args *args, int i);
void	cleanup(t_philo *philo, t_args *args);
void	philo_think(t_philo *philo, t_args *args);
void	philo_take_forks(t_philo *philo, t_args *args);

// routine
void	*philo_routine(void *arg);

#endif
