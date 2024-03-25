/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:00:46 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/25 15:50:03 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/select.h>
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
	int			eating;
	int			num_of_philo;
	int			target_meals;
	int			is_dead;
	pthread_t	thread;
	t_mtx		*first_fork;
	t_mtx		*second_fork;
	t_mtx		*write_lock;
	t_mtx		*dead_lock;
	t_mtx		*meal_lock;
}	t_philo;

typedef struct s_program
{
	int			dead_flag;
	t_mtx		write_lock;
	t_mtx		dead_lock;
	t_mtx		meal_lock;
	t_philo		*philos;
} t_program;

int	is_number(const char *s);
int	ft_atoi(const char *str);
int	ft_usleep(size_t	milliseconds);
int	philosopher_dead(t_philo *philo, size_t	time_to_die);
int	check_if_dead(t_philo *philos);
int	check_if_all_ate(t_philo *philos);
int	create_threads(t_program *program, t_mtx *forks);
int	error_exit(const char *s);
size_t	get_current_time(void);
void	ft_putstr_fd(char *s, int fd);
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_of_philo);
void	init_philo(t_philo *philos, t_program *program, t_mtx *forks, char **av);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	*monitor(void *pointer);
void	print_message(char *message, t_philo *philo, int id);
void	destroy_all(char *s, t_program *program, pthread_mutex_t *forks);

#endif
