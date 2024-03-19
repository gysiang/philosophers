/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:27:52 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/19 15:55:29 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	thinking(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	sleeping(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eating(t_philo *philo)
{
	// picks up one fork
	pthread_mutex_lock(philo->first_fork);
	print_message("has taken a fork", philo, philo->id);
	// if there are only 1 philo, just delay the thread until
	// philo dies
	if (philo->num_of_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->first_fork);
		return ;
	}
	// picks up second fork
	pthread_mutex_lock(philo->second_fork);
	print_message("has taken a fork", philo, philo->id);
	// starts to eat
	print_message("is eating", philo, philo->id);
	// add meals eaten
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_counter++;
	philo->eating == 1;
	pthread_mutex_unlock(philo->meal_lock);
	// time for the philosopher to finish his meal
	ft_usleep(philo->time_to_eat);
	// philo releases both forks
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
