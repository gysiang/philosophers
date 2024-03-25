/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:57 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/25 16:24:26 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_input(char **av)
{
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) <= 0
			|| is_number(av[1]))
	{
		error_exit("Invalid number of philosopher");
	}
	if (ft_atoi(av[2]) <= 60 || is_number(av[2]))
	{
		error_exit("Invalid time to die");
	}
	if (ft_atoi(av[3]) <= 60 || is_number(av[3]))
	{
		error_exit("Invalid time to eat");
	}
	if (ft_atoi(av[4]) <= 60 || is_number(av[4]))
	{
		error_exit("Invalid time to sleep");
	}
	if (av[5] && (ft_atoi(av[5]) < 0 || is_number(av[5])))
	{
		error_exit("Invalid no of meals");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_program	program;
	t_philo		philos[MAX_PHILO];
	t_mtx		forks[MAX_PHILO];

	if (ac == 5 || ac == 6)
	{
		if (!check_input(av))
			printf("%s\n", "The input is okay");
		init_program(&program, philos);
		init_philo(philos, &program, forks, av);
		init_forks(forks, ft_atoi(av[1]));
		create_threads(&program, forks);
		destroy_all(NULL, &program, forks);
	}
	else
		error_exit("Wrong Input: ./philo time_to_die time_to eat time_to_sleep [min meals]");
	return (0);
}
/**
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
**/
