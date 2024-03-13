/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:00:46 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/13 17:27:30 by gyong-si         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	int			id;
	int			meals_counter;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	size_t		last_meal;
	int			num_of_philo;
	int			target_meals;
	bool		is_dead;
	pthread_t	thread_id;
	pthread_t	*first_fork;
	pthread_t	*second_fork;
	t_mtx		*write_lock;
	t_mtx		*dead_lock;
	t_mtx		*meal_lock;
}	t_philo;

typedef struct s_program
{
	bool		dead_flag;
	t_mtx		write_lock;
	t_mtx		dead_lock;
	t_mtx		meal_lock;
	t_philo		*philos;
} t_program;

int	is_number(const char *s);
int	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	error_exit(const char *s);
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_of_philo);

#endif
