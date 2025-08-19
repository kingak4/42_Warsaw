/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 11:34:28 by kikwasni         ###   ########.fr       */
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
        print_action(philo, "has taken a right fork");

        pthread_mutex_lock(philo->left_fork);
        if (is_dead(philo))
        {
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            return (1);
        }
        print_action(philo, "has taken a left fork");
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        if (is_dead(philo))
        {
            pthread_mutex_unlock(philo->left_fork);
            return (1);
        }
        print_action(philo, "has taken a left fork");

        pthread_mutex_lock(philo->right_fork);
        if (is_dead(philo))
        {
            pthread_mutex_unlock(philo->right_fork);
            pthread_mutex_unlock(philo->left_fork);
            return (1);
        }
        print_action(philo, "has taken a right fork");
    }
    return (0);
}
//int philo_take_forks(t_philo *philo)
//{
//    if (philo->id % 2 == 0) // prostsze: parzysty bierze lewy, nieparzysty prawy
//    {
//        pthread_mutex_lock(philo->left_fork);
//        if (philo->died)
//        {
//            pthread_mutex_unlock(philo->left_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a left fork");

//        pthread_mutex_lock(philo->right_fork);
//        if (philo->died)
//        {
//            pthread_mutex_unlock(philo->right_fork);
//            pthread_mutex_unlock(philo->left_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a right fork");
//    }
//    else
//    {
//        pthread_mutex_lock(philo->right_fork);
//        if (philo->died)
//        {
//            pthread_mutex_unlock(philo->right_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a right fork");

//        pthread_mutex_lock(philo->left_fork);
//        if (philo->died)
//        {
//            pthread_mutex_unlock(philo->left_fork);
//            pthread_mutex_unlock(philo->right_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a left fork");
//    }
//    return (0);
//}
//int	philo_take_forks(t_philo *philo)
//{
//	if (philo->left_fork > philo->right_fork)
//	{
//		pthread_mutex_lock(philo->right_fork);
//		if (philo->died)
//		{
//			pthread_mutex_unlock(philo->right_fork);
//			return (1);
//		}
//		print_action(philo, "has taken a right fork");
//		pthread_mutex_lock(philo->left_fork);
//		if (philo->died)
//		{
//			pthread_mutex_unlock(philo->left_fork);
//			pthread_mutex_unlock(philo->right_fork);
//			return (1);
//		}
//		print_action(philo, "has taken a left fork");
//	}
//	else
//	{
//		pthread_mutex_lock(philo->left_fork);
//		if (philo->died)
//		{
//			pthread_mutex_unlock(philo->left_fork);
//			return (1);
//		}
//		print_action(philo, "has taken a left fork");

//		pthread_mutex_lock(philo->right_fork);
//		if (philo->died)
//		{
//			pthread_mutex_unlock(philo->right_fork);
//			pthread_mutex_unlock(philo->left_fork);
//			return (1);
//		}
//		print_action(philo, "has taken a right fork");
//	}
//	return (0);
//}
//int philo_take_forks(t_philo *philo)
//{
//    if (philo->left_fork > philo->right_fork)
//    {
//        pthread_mutex_lock(philo->right_fork);
//        if (is_dead(philo))
//        {
//            pthread_mutex_unlock(philo->right_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a right fork");

//        pthread_mutex_lock(philo->left_fork);
//        if (is_dead(philo))
//        {
//            pthread_mutex_unlock(philo->left_fork);
//            pthread_mutex_unlock(philo->right_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a left fork");
//    }
//    else
//    {
//        pthread_mutex_lock(philo->left_fork);
//        if (is_dead(philo))
//        {
//            pthread_mutex_unlock(philo->left_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a left fork");

//        pthread_mutex_lock(philo->right_fork);
//        if (is_dead(philo))
//        {
//            pthread_mutex_unlock(philo->right_fork);
//            pthread_mutex_unlock(philo->left_fork);
//            return (1);
//        }
//        print_action(philo, "has taken a right fork");
//    }
//    return (0);
//}
void philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep);
}

void philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

//int	philo_eat(t_philo *philo, t_args *args)
//{
//	// lock forks
//	if (philo_take_forks(philo))
//		return (1);

//	// print the message
//	print_action(philo, "is eating");
//	// update info about the thread
//	pthread_mutex_lock(&philo->meal_mutex);
//	philo->last_meal = get_current_time();
//	philo->eat_count++;
//	pthread_mutex_unlock(&philo->meal_mutex);
//	ft_usleep(args->time_to_eat);
//	// unlock forks in the same order as they were locked
//	if (philo->right_fork < philo->left_fork)
//	{
//		pthread_mutex_unlock(philo->right_fork);
//		pthread_mutex_unlock(philo->left_fork);	
//	}
//	else
//	{
//		pthread_mutex_unlock(philo->left_fork);
//		pthread_mutex_unlock(philo->right_fork);
//	}
//	return (0);
//	// wychodzimy z „room”, pozwalając innym wejść
//	// room_leave(args);
//}
//int philo_eat(t_philo *philo, t_args *args)
//{
//	pthread_mutex_lock(&args->death);
//	if (philo->died == 1)
//	{
//		pthread_mutex_unlock(&args->death);
//		return (1);
//	}
//	pthread_mutex_unlock(&args->death);
//    if (philo_take_forks(philo))
//        return (1);

//    print_action(philo, "is eating");

//    pthread_mutex_lock(&philo->meal_mutex);
//    philo->last_meal = get_current_time();
//    philo->eat_count++;
//    pthread_mutex_unlock(&philo->meal_mutex);

//    ft_usleep(args->time_to_eat);

//    // zawsze unlockujemy w tej samej kolejności jak lock
//    pthread_mutex_unlock(philo->left_fork);
//    pthread_mutex_unlock(philo->right_fork);

//    return (0);
//}
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
//int philo_eat(t_philo *philo, t_args *a)
//{
//    if (is_dead(philo))
//        return (1);

//    if (philo_take_forks(philo))
//        return (1);
//    print_action(philo, "is eating");

//    pthread_mutex_lock(&a->philo->meal_mutex);
//    philo->last_meal = get_current_time();
//    philo->eat_count++;
//    pthread_mutex_unlock(&a->philo->meal_mutex);

//    ft_usleep(a->time_to_eat);

//    pthread_mutex_unlock(philo->left_fork);
//    pthread_mutex_unlock(philo->right_fork);

//    return (0);
//}
void	*philo_routine(void *arg)
{
	t_philo	*p = (t_philo *)arg;
	t_args	*a = p->args;

	// change: not just == 1, but != 0 (philos with odd id will wait)
	if (p->id % 2 != 0)
		ft_usleep(1);
	while (1)
	{
		pthread_mutex_lock(&a->death);
		if (p->died)
		{
			pthread_mutex_unlock(&a->death);
			break ;
		}
		pthread_mutex_unlock(&a->death);
		if (philo_eat(p, a))
			return (NULL);
		if (p->died || (a->must_eat_count > 0 && p->eat_count >= a->must_eat_count))
			break;	
		philo_sleep(p);
		pthread_mutex_lock(&a->death);
		if (p->died)
			break ;
		pthread_mutex_unlock(&a->death);
		philo_think(p);
	}
	return (NULL);
}
