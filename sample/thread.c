/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:26:41 by gyong-si          #+#    #+#             */
/*   Updated: 2024/03/06 13:01:47 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void exit_on_error(int *num, int exit_code)
{
    free(num);
    exit(exit_code);
}

void *routine_2(void *arg)
{
    int *num;
    int i;

    num = (int *)arg;
    i = 0;
    while (i < 100000)
    {
        //pthread_mutex_lock(&mutex);
        (*num)++;
        //pthread_mutex_unlock(&mutex);
        i++;
    }
    return (NULL);
}

void example_3()
{
    int *num;
    pthread_t t1;
    pthread_t t2;

    num = malloc(sizeof(int));
    if (num == NULL)
        exit(1);
    *num = 0;
    if (pthread_create(&t1, NULL, routine_2, num))
        exit_on_error(num, 2);
    if (pthread_create(&t2, NULL, routine_2, num))
        exit_on_error(num, 2);
    if (pthread_join(t1, NULL))
        exit_on_error(num, 3);
    if (pthread_join(t2, NULL))
        exit_on_error(num, 3);
    printf("Num: %d\n", *num);
}

void *print_hello()
{
    int i;

    i = 0;
    while (i < 100)
    {
        printf("Hello\n");
        i++;
        usleep(100);
    }
    return (NULL);
}

void *print_world()
{
    int i;

    i = 0;
    while (i < 100)
    {
        //pthread_mutex_lock(&mutex);
        printf("\t\tWorld\n");
        //pthread_mutex_unlock(&mutex);
        i++;
        usleep(100);
    }
    return (NULL);
}

void example_2()
{
    pthread_t t1;
    pthread_t t2;

    if (pthread_create(&t1, NULL, print_hello, NULL))
        exit(1);
    if (pthread_create(&t2, NULL, print_world, NULL))
        exit(1);
    if (pthread_join(t1, NULL))
        exit(1);
    if (pthread_join(t2, NULL))
        exit(1);
}

void example_1()
{
    print_hello();
    print_world();
}

int main()
{
    example_2();

    return (0);
}
