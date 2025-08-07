/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/07 17:20:19 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1);
	while (1)
	{
		// eating function
		// sleeping function
		// thinking
	}
}

void	philo_think(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->print_mutex);
	print_action(philo, "is thinking");
	pthread_mutex_unlock(&args->print_mutex);
	usleep(1000);
}

void	philo_take_forks(t_philo *philo, t_args *args)
{
	philo->left_fork = &args->forks[philo->id];
	philo->right_fork = &args->forks[(philo->id + 1) % args->philo_count];
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
}

//void	philo_eat(t_philo *philo, t_args *args)
//{
//	pthread_mutex_lock(philo->meal_mutex);
//}
//📌 Krok po kroku — co musi się wydarzyć w philo_eat()
//🔐 Zablokuj dostęp do danych współdzielonych:

//Chcesz zmienić philo->last_meal i philo->meals_eaten.

//To są dane współdzielone przez wątki, więc zabezpiecz je mutexem.

//🕰️ Zapisz czas ostatniego posiłku:

//Zapisz aktualny timestamp (czas) jako philo->last_meal.

//Dzięki temu monitorujący wątek może sprawdzić, czy filozof nie głoduje.

//🍽️ Wydrukuj akcję „is eating”:

//Użyj funkcji print_action(philo, "is eating").

//➕ Zwiększ licznik zjedzonych posiłków:

//Jeśli masz ograniczenie (np. każdy filozof musi zjeść X razy), to licz meals_eaten.

//💤 Zasymuluj czas jedzenia:

//Użyj usleep(args->time_to_eat * 1000), żeby „symulować” jedzenie.

//🔓 Odblokuj mutexy (widełki):

//Po zakończeniu jedzenia zwolnij oba mutexy (lewy i prawy widelec).