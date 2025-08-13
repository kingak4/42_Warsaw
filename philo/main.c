/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:18:56 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/13 14:57:33 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int ac, char **av)
//{
//	t_args	args;

//	init_args_struct(&args);
//	if (!parse_args(ac, av, &args))
//		return (1);
//	//args.time_start = get_current_time();
//	printf("Philo count     : %d\n", args.philo_count);
//	printf("Time to die     : %d ms\n", args.time_to_die);
//	printf("Time to eat     : %d ms\n", args.time_to_eat);
//	printf("Time to sleep   : %d ms\n", args.time_to_sleep);
//	if (args.must_eat_count != -1)
//		printf("Must eat count  : %d times\n", args.must_eat_count);
//	else
//		printf("Must eat count  : not specified\n");
//	if (args.philo_count == 1)
//	{
//		t_philo	philo;
//		philo.args = &args;
//		handle_one_philo(&philo);
//		return (0);
//	}
//	return (0);
//}
int main(int argc, char **argv)
{
	t_args args;
	t_philo *philo;
	pthread_t monitor_thread;
	if (!parse_args(argc, argv, &args))
		return (1);
	init_args_struct(&args);
	philo = args.philo;
	start_philo(philo, &args);
	if (pthread_create(&monitor_thread, NULL, monitor, philo->args) != 0)
	{
		printf("Error: monitor thread creation failed\n");
		cleanup(philo, &args);
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	cleanup(philo, &args);
	return 0;
}
