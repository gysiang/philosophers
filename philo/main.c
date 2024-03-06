/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:57 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/06 15:42:31 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	run_philo(char **av)
{

}

int	check_input(char **av)
{
	int	i;
	int	num;

	i = 1;
	while (av[i] != NULL)
	{
		if (!is_number(av[i]) || ft_atoi(av[i]) < 1 || ft_atoi(av[i] > 200))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 6)
	{
		if (!check_input(av))
		{
			ft_putstr_fd("Wrong Inputs\n", 2);
			exit(EXIT_FAILURE);
		}
		run_philo(av);
	}
	return (0);
}
/**
number_of_philo
time_to_die
time_to_eat
time_to_sleep
[num_of_times_to_eat]
**/
