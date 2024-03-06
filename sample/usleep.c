/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:03:08 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/06 14:22:55 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	example()
{
	struct timeval	start_time;
	struct timeval	end_time;
	long requested_sleep_time;
	long actual_sleep_time;

	requested_sleep_time = 200 * 1000;
	gettimeofday(&start_time, NULL);
	usleep(requested_sleep_time);
	gettimeofday(&end_time, NULL);
	actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 +
		(end_time.tv_usec - start_time.tv_usec);

	printf("Requested Sleep Time: %ld microseconds\n", requested_sleep_time);
	printf("Actual Sleep Time: %ld microseconds\n", actual_sleep_time);
}

int	main(void)
{
	example();
	return (0);
}
