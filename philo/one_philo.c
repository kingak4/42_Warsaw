/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:02 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/15 09:11:19 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_one_philo(t_philo *philo)
{
	philo->id = 1;
	philo->last_meal = get_current_time();
	print_action(philo, "has taken a fork");
	usleep(philo->args->time_to_die * 1000);
	print_action(philo, "died");
	philo->died = 1;
	exit(0);
}
