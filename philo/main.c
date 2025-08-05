/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:18:56 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/05 12:41:05 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;

	init_args_struct(&args);
	if (!parse_args(ac, av, &args))
		return (1);
	printf("Philo count     : %d\n", args.philo_count);
	printf("Time to die     : %d ms\n", args.time_to_die);
	printf("Time to eat     : %d ms\n", args.time_to_eat);
	printf("Time to sleep   : %d ms\n", args.time_to_sleep);
	if (args.must_eat_count != -1)
		printf("Must eat count  : %d times\n", args.must_eat_count);
	else
		printf("Must eat count  : not specified\n");
	return (0);
}
