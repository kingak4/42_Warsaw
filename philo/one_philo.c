/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:02 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/21 08:45:13 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_one_philo(t_philo *philo, t_args *args)
{
	philo->id = 1;
	args->time_start = get_current_time();
	philo->last_meal = get_current_time();
	print_action(philo, "has taken a fork");
	usleep(args->time_to_die * 1000);
	print_action(philo, "died");
	philo->died = 1;
	return ;
}
