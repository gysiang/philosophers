/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:00:46 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/07 23:13:38 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_data
{
	int		num;
	int		num_of_meals;
	size_t	die_time;
	size_t	eat_time
	size_t	sleep_time;
	size_t	start_time;

} t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	pthread_mutex_t	last_meal_mutex;
	size_t			last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
} t_philo;

int	ft_atoi(const char *str);
int	is_number(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
