/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:09 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/06 13:53:40 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

uint64_t	get_time(void)
{
	struct	timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	example_1(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("%ld seconds\n", time.tv_sec);
	printf("%ld seconds\n", time.tv_usec);

	printf("\n%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
}

void	example_2()
{
	uint64_t	start_time;
	uint64_t	now;

	start_time = get_time();
	usleep(10000);
	now = get_time();
	printf("%ld milliseconds passed since start\n", now - start_time);
}

int	main()
{
	example_1();
	example_2();

	return (0);
}
