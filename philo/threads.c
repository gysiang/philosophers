/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:42:40 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/19 17:04:43 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

/**
 * Check if the philo is dead if philo is dead return 1
 * else return 0
*/

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->is_dead == true)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	print_message(char *message, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!check_death(philo))
		printf("%zu %d %s\n", time, id, message);
	pthread_mutex_unlock(philo->write_lock);
}

/**
 * Routine for philosopher
 * 1. delay even id philo
 * 2. if philo is not dead, start eating
 * 3. sleep then think
*/
void	*philo_routine(void	*pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_death(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (pointer);
}

/**
 * Create all the philo threads
 * Need to have an observer thread
*/
int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	// create the observer thread
	if (pthread_create(&observer, NULL, &monitor, program->philos))
			destroy_all("Thread creation error", program, forks);
	i = 0;
	// create all the philosopher thread
	while (i < program->philos[0].num_of_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	// wait for the observer thread to execute
	if (pthread_join(observer, NULL) != 0)
			destroy_all("Thread join error", program, forks);
	// wait for the philosopher thread to execute
	while (i < program->philos[0].num_of_philo)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
				destroy_all("Thread join error", program, forks);
		i++;
	}
	return (0);
}
