/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:18:35 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/14 12:45:04 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_args
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	print_mutex;

	// NEW: room = N-1 ochrona przed deadlockiem
	pthread_mutex_t	room_mutex;
	int				in_room;

	long			time_start;
	int				died;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}		t_args;

void	init_args_struct(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&args->print_mutex, NULL);
	// NEW:
	pthread_mutex_init(&args->room_mutex, NULL);
	args->in_room = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_count);
	if (!args->forks)
		return ;
	while (i < args->philo_count)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	args->philo = malloc(sizeof(t_philo) * args->philo_count);
	if (!args->philo)
		return ;
	i = 0;
	while (i < args->philo_count)
	{
		pthread_mutex_init(&args->philo[i].meal_mutex, NULL);
		i++;
	}
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

	// NEW:
	pthread_mutex_destroy(&args->room_mutex);
	pthread_mutex_destroy(&args->print_mutex);
	free(philo);
}
void	room_enter(t_args *a)
{
	while (1)
	{
		pthread_mutex_lock(&a->room_mutex);
		if (a->in_room < a->philo_count - 1)
		{
			a->in_room++;
			pthread_mutex_unlock(&a->room_mutex);
			break;
		}
		pthread_mutex_unlock(&a->room_mutex);
		usleep(1000); // mała pauza, żeby nie kręcić się w kółko
	}
}

void	room_leave(t_args *a)
{
	pthread_mutex_lock(&a->room_mutex);
	a->in_room--;
	pthread_mutex_unlock(&a->room_mutex);
}

void	philo_take_forks(t_philo *philo)
{
	t_args *a = philo->args;

	// delikatne rozbicie startu co drugiego filozofa
	if (philo->id % 2 == 0)
		usleep(1000);

	// Wejście do „room” (max N-1 naraz próbuje jeść)
	room_enter(a);

	// ZAWSZE ta sama kolejność — najpierw lewy, potem prawy
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");

	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo, t_args *args)
{
	// Ustawiamy czas ostatniego posiłku i licznik w JEDNYM krytycznym bloku
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_mutex);

	print_action(philo, "is eating");
	usleep(args->time_to_eat * 1000);

	// odkładamy widelce w stałej kolejności
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);

	// wychodzimy z „room”, pozwalając innym wejść
	room_leave(args);
}
void	*philo_routine(void *arg)
{
	t_philo	*p = (t_philo *)arg;
	t_args	*a = p->args;

	// mały offset startu – zmniejsza szansę na kolizje
	if (p->id % 2 == 1)
		usleep(500);
	while (1)
	{
		if (a->died)
			break;
		philo_think(p);
		if (a->died)
			break;
		philo_take_forks(p);
		if (a->died)
		{
			// mamy już widelce – oddaj, żeby nie trzymać blokad
			pthread_mutex_unlock(p->right_fork);
			pthread_mutex_unlock(p->left_fork);
			room_leave(a);
			break;
		}
		philo_eat(p, a);
		if (a->died || (a->must_eat_count > 0 && p->eat_count >= a->must_eat_count))
			break;
		philo_sleep(p, a);
	}
	return (NULL);
}

void	*monitor(void *args)
{
	int		i;
	int		done;
	long	last_meal_c;
	t_args	*a = (t_args *)args;

	a->died = 0;
	while (!a->died)
	{
		i = 0;
		done = 0;
		while (i < a->philo_count)
		{
			pthread_mutex_lock(&a->philo[i].meal_mutex);
			last_meal_c = get_current_time() - a->philo[i].last_meal;
			if (a->must_eat_count > 0 && a->philo[i].eat_count >= a->must_eat_count)
				done++;
			pthread_mutex_unlock(&a->philo[i].meal_mutex);

			if (last_meal_c > a->time_to_die)
			{
				a->died = 1;
				print_action(&a->philo[i], "died");
				return (NULL);
			}
			i++;
		}
		// NEW: jeśli wszyscy zjedli wymaganą liczbę razy – kończymy
		if (a->must_eat_count > 0 && done == a->philo_count)
			return (NULL);

		usleep(5000);
	}
	return (NULL);
}
void	start_philo(t_philo *philo, t_args *args)
{
	int	i, res;

	if (args->philo_count == 1)
	{
		handle_one_philo(&philo[0]);
		return;
	}
	args->time_start = get_current_time();
	for (i = 0; i < args->philo_count; i++)
		init_philo(&philo[i], args, i);

	for (i = 0; i < args->philo_count; i++)
	{
		res = pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		if (res != 0)
			handle_creation_error(philo, args, i);
	}
	for (i = 0; i < args->philo_count; i++)
		pthread_join(philo[i].thread, NULL);
}
