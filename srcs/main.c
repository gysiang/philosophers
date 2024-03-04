/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:57 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/04 16:13:42 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void* arg)
{
	int index;

	index = *(int *)arg;
	printf("print the arg %d/n", index);
	free(arg);
}

int	main(int ac, char **av)
{
	if (ac == 6)
	{
		int			num_of_philo;
		int			i;
		int			*a;
		pthread_t	th[num_of_philo];

		i = 0;
		num_of_philo = ft_atoi(av[1]);
		while (num_of_philo > i)
		{
			a = malloc(sizeof(int));
			if (!a)
				return (1);
			*a = i;
			if (pthread_create(&th[i], NULL, &routine, a) != 0)
			{
				perror("Failed to create thread");
			}
			i++;
		}
		i = 0;
		while (num_of_philo > i)
		{
			if (pthread_join(th[i], NULL) != 0)
			{
				perror("Failed to join thread");
				return (1);
			}
			i++;
		}
	}
	else
	{
		printf("Should have 5 arguments");
		return (1);
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
