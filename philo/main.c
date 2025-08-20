/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:18:56 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/19 16:40:38 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_args args;
	t_philo *philo;
	//pthread_t monitor_thread;
	if (!parse_args(argc, argv, &args))
		return (1);
	if (!init_args_struct(&args))
		return (1);
	philo = args.philo;
	start_philo(philo, &args);
	//if (pthread_create(&monitor_thread, NULL, monitor, philo->args) != 0)
	//{
	//	printf("Error: monitor thread creation failed\n");
	//	cleanup(philo, &args);
	//	return (1);
	//}
	//pthread_join(monitor_thread, NULL);
	cleanup(philo, &args);
	return 0;
}