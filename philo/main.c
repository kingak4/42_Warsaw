/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:18:56 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/21 10:38:30 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (!parse_args(argc, argv, &args))
		return (1);
	if (!init_args_struct(&args))
		return (1);
	philo = args.philo;
	if (args.philo_count == 1)
	{
		init_philo(&philo[0], &args, 0);
		handle_one_philo(&philo[0], &args);
		cleanup(philo, &args);
		return (0);
	}
	start_philo(philo, &args, 0, 0);
	cleanup(philo, &args);
	return (0);
}
