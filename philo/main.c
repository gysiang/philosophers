/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:57 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/19 17:08:06 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	check_input(char **av)
{
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) <= 0
			|| is_number(av[1]))
			return(ft_putstr_fd("Invalid number of philosopher", 2));
	if (ft_atoi(av[2]) <= 60 || is_number(av[2]))
			return(ft_putstr_fd("Invalid time to die", 2));
	if (ft_atoi(av[3]) <= 60 || is_number(av[3]))
			return(ft_putstr_fd("Invalid time to eat", 2));
	if (ft_atoi(av[4]) <= 60 || is_number(av[4]))
			return(ft_putstr_fd("Invalid time to sleep", 2));
	if (av[5] && (ft_atoi(av[4]) < 0 || is_number(av[4])))
			return(ft_putstr_fd("Invalid time to sleep", 2));
}

int	main(int ac, char **av)
{
	t_program	program;
	t_philo		philos[MAX_PHILO];
	t_mtx		forks[MAX_PHILO];

	if (ac == 5 || ac == 6)
	{
		check_input(av);
		/**This parts only initalise the values*/
		init_program(&program, philos);
		init_philo(philos, &program, &forks, av);
		init_forks(&forks, ft_atoi(av[1]));
		/** Need to create the necessary threads and join them*/
		create_threads(&program, forks);
		/** clear all the memory leaks*/
		destroy_all(NULL, &program, forks);
	}
	else
		error_exit("Wrong Input: ./philo time_to_die time_to eat time_to_sleep [min meals]");
	return (0);
}
/**
 * ./philo 5 800 200 200 [5]
number_of_philo
time_to_die
time_to_eat
time_to_sleep
[num_of_times_to_eat]
**/
