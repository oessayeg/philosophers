/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:56:58 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:51:58 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->n_philo)
	{
		philo[i].state = 0;
		if (pthread_create(&philo[i].th, NULL, &routine, &philo[i]) != 0)
		{
			write(2, "Pthread_create Failed !\n", 24);
			return (1);
		}
		usleep(100);
		i++;
	}
	while (1)
	{
		if (check_death_time(philo))
			return (0);
		if (philo[0].rules->n_meals > 0 && check_meals(philo))
			return (0);
		usleep(100);
	}
	return (0);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		take_forks(philo);
		new_sleep(philo->rules->time_to_eat);
		put_forks(philo);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->right_fork]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork]);
	print_msg(philo, FORK);
	print_msg(philo, EAT);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
	print_msg(philo, SLEEP);
	new_sleep(philo->rules->time_to_sleep);
	print_msg(philo, THINK);
}
