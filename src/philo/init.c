/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:16:30 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/25 16:42:44 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->target_meals = ft_atoi(argv[5]);
	else
		philo->target_meals = -1;
}

void	init_philo(t_philo *philos, t_program *program, t_mtx *forks, char **av)
{
	int	i;
	int	num_of_philo;

	i = 0;
	num_of_philo = ft_atoi(av[1]);
	while (i < num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_counter = 0;
		init_input(&philos[i], av);
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].is_dead = 0;
		philos[i].first_fork = &forks[i];
		if (i == 0)
			philos[i].second_fork = &forks[philos[i].num_of_philo - 1];
		else
			philos[i].second_fork = &forks[i - 1];
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
