/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:57:38 by root              #+#    #+#             */
/*   Updated: 2025/08/09 00:59:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Start monitora:
// Monitor otrzymuje wskaźnik do t_args, w którym są wszystkie dane i tablica filozofów.
// W pętli (np. co 5 ms):
// Dla każdego filozofa:
// Zablokuj mutex meal_mutex filozofa (chroni dane last_meal, eat_count).
// Pobierz last_meal i eat_count.
// Odblokuj mutex.
// Oblicz czas od ostatniego posiłku: current_time - last_meal.
// Jeśli czas ten jest większy niż time_to_die:
// Ustaw globalną flagę died (chronioną mutexem lub atomic).
// Wypisz, że filozof umarł (print_death).
// Zakończ pętlę monitora i sygnalizuj zakończenie programu.
// Jeśli jest ustawiony limit must_eat_count:
// Sprawdź, czy każdy filozof ma eat_count >= must_eat_count.
// Jeśli tak, zakończ program (ustaw died lub stop).
// Po wykryciu warunku zakończenia:
// Zakończ działanie monitora,
// Inne wątki odczytają flagę died i zakończą pętle rutyn.
// 1. monitor(void *args_ptr):
//    - rzutuj args_ptr na t_args*
//    - pętla while (!args->died):
//        - dla każdego filozofa:
//            - pthread_mutex_lock(&philo->meal_mutex)
//            - sprawdź czas od ostatniego posiłku
//            - pthread_mutex_unlock(&philo->meal_mutex)
//            - jeśli przekroczony time_to_die:
//                - ustaw args->died = 1
//                - print_death(philo)
//                - break pętlę
//        - jeśli must_eat_count > 0:
//            - sprawdź, czy wszyscy zjedli minimum
//            - jeśli tak, ustaw args->died = 1
//        - usleep(5 ms)
//    - return NULL
