/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:50:00 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/25 16:38:23 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	philosopher_dead(t_philo *philo, size_t	time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
			&& philo->eating == 0)
			return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philo)
	{
		if (philosopher_dead(&philos[i], philos[i].time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[i].dead_lock);
			philos[i].is_dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	have_eaten;

	i = 0;
	have_eaten = 0;
	if (philos[0].target_meals == -1)
		return (0);
	while (i < philos[0].num_of_philo)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_counter >= philos[i].target_meals)
			have_eaten++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (have_eaten == philos[0].num_of_philo)
	{
		pthread_mutex_lock(philos[i].dead_lock);
		philos[i].is_dead = 1;
		pthread_mutex_unlock(philos[i].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo *philos;

	philos = (t_philo *)pointer;
	while (1)
	{
		if (check_if_dead(philos) || check_if_all_ate(philos))
			break ;
	}
	return (pointer);
}
