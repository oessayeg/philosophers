/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:23:21 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:38:10 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	m_fail(void)
{
	write(2, "Malloc Failed !\n", 16);
	return (0);
}

int	ft_atoi(char *nb)
{
	int	i;
	int	return_value;

	return_value = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		return_value = return_value * 10 + (nb[i] - 48);
		i++;
	}
	return (return_value);
}

long int	give_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(t_philo *philo, int option)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("%ld ", give_time() - philo->rules->sim_start);
	if (option == 1)
		printf("%d has taken a fork\n", philo->philo_id);
	else if (option == 2)
	{
		printf("%d is eating\n", philo->philo_id);
		pthread_mutex_lock(&philo->mutex);
		philo->state = 2;
		philo->last_eat = give_time();
		philo->eaten_meals++;
		pthread_mutex_unlock(&philo->mutex);
	}
	else if (option == 3)
	{
		printf("%d is sleeping\n", philo->philo_id);
		pthread_mutex_lock(&philo->mutex);
		philo->state = 0;
		pthread_mutex_unlock(&philo->mutex);
	}
	else if (option == 4)
		printf("%d is thinking\n", philo->philo_id);
	else
	{
		print_msg2(option, philo);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->print_mutex);
}

void	new_sleep(int t_to_sleep)
{
	long int	time;

	time = give_time() + t_to_sleep;
	while (give_time() < time)
		usleep(200);
}
