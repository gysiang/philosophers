/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:57 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/09 23:55:42 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	init_data(t_data data,char **av)
{
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->num_of_times_to_eat = ft_atoi(av[5]);
	else
		data->num_of_times_to_eat = -1;
}

void	init_fork(pthread_mutext_t *forks, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutext_init(&fork[i], NULL);
		i++:
	}
}

int	check_number(char **av)
{
	int	i;
	int	num;

	i = 1;
	while (av[i] != NULL)
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_params(char **av)
{
	// first param is no of philo
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) <= 0
			|| !is_number(av[1]))
	{
		ft_putstr_fd("Invalid number of philosophers", 2);
		return (1);
	}
	// second is the time to die since last meal
	if (ft_atoi(av[2]) <= 0 || !is_number(av[2]))
	{
		ft_putstr_fd("Invalid time to die", 2);
		return (1);
	}
	// third is the time taken to eat
	if (ft_atoi(av[3]) <= 0 || !is_numer(av[3]))
	{
		ft_putstr_fd("Invalid time to eat", 2);
		return (1);
	}
	// fourth is time taken to sleep
	if (ft_atoi(av[4]) <= 0 || !is_number(av[4]))
	{
		ft_putstr_fd("Invalid time to sleep", 2);
		return (1);
	}
	// fiveth is optional, the min amt of meals taken
	if (av[5] && (ft_atoi(av[5]) || !is_number(av[5])))
	{
		ft_putstr_fd("Invalid number of times each philosopher must eat", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_program			program;
	t_philo				philos[MAX_PHILO];
	pthread_mutext_t 	forks[MAX_PHILO];

	if (ac != 5 || ac != 6)
		ft_putstr_fd("Argument count is wrong\n", 2);
	// check if all arguments are num
	if (check_valid_params(av))
		return (1);
	init_program(&program, philos);
	init_fork(&fork, ft_atoi(av[1]));
	return (0);
}
/**
number_of_philo
time_to_die
time_to_eat
time_to_sleep
[num_of_times_to_eat]
**/
