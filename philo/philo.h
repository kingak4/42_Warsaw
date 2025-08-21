/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/20 17:28:27 by kikwasni         ###   ########.fr       */
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
	int				died;
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
	pthread_mutex_t	death;
	long			time_start;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}		t_args;

// get_current_time() → „Która jest teraz godzina w ms od 1970?”
// get_relative_time() → „Ile czasu minęło od startu programu?”

int		is_valid_number(char *str);
int		is_int_range(char *str);
int		is_valid_input(char *arg);
long	ft_atol(const char *nptr);
int		init_args_struct(t_args *args);
int		parse_args(int ac, char **av, t_args *args);
long	get_current_time(void);
long	get_relative_time(t_args *args);
void	print_action(t_philo *philo, char *message);
int		warp(void);
void	handle_one_philo(t_philo *philo, t_args *args);
void	init_philo(t_philo *philo, t_args *args, int i);
void	cleanup(t_philo *philo, t_args *args);
void	start_philo(t_philo *philo, t_args *args);

//routine
void	*philo_routine(void *arg);
void	philo_think(t_philo *philo);
// void	philo_take_forks(t_philo *philo);
int		philo_take_forks(t_philo *philo);
//void	philo_eat(t_philo *philo, t_args *args);
int		philo_eat(t_philo *philo, t_args *args);
// void	philo_sleep(t_philo *philo, t_args *args);
void	philo_sleep(t_philo *philo);
void	*monitor(void *a);
int	is_any_philo_dead(t_args *data);
//utils.c
int		ft_usleep(size_t time_in_ms);
int		is_dead(t_philo *p);
int		all_philos_eaten(t_args *data);
int		has_philo_eaten_max(t_args *data, int i);
int		all_philos_eaten(t_args *data);
void	increment_meals(t_args *data, int i);
void	check_philos(t_args *data);
#endif
