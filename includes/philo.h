/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:00:46 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/09 23:52:01 by gyong-si         ###   ########.fr       */
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

# define MAX_PHILO 200
# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
#endif

typedef struct s_data
{
	int		num_of_philo;
	int		num_of_meals;
	size_t	die_time;
	size_t	eat_time
	size_t	sleep_time;
	size_t	start_time;
} t_data;

typedef struct s_fork
{
	bool	is_used;
	pthread_mutex_t	locked;
} t_fork

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				is_dead;
	pthread_mutex_t	last_meal_mutex;
	size_t			last_meal_time;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_data			params;
} t_philo;

typedef struct s_program
{
	int				is_dead;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t write_lock;
	t_philo			*philos;
}	t_program

int	ft_atoi(const char *str);
int	is_number(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif

// max no of philo <= 200
