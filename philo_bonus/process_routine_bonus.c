/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:05:02 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/06 13:11:11 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

int	init_processes(t_philo *philos)
{
	int	n;
	int	i;

	n = philos->par->n_philo;
	i = -1;
	philos->par->sim_start = give_time();
	while (++i < n)
	{
		philos[i].process_id = fork();
		if (philos[i].process_id == -1)
		{
			write(2, "Fork Failed !\n", 14);
			return (1);
		}
		if (philos[i].process_id == 0)
		{
			if (philos[i].philo_id % 2 == 0)
				usleep(500);
			philo_routine(&philos[i]);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}

void	*thread_watcher(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->last_eat = give_time();
	while (1)
	{
		if (give_time() - philo->last_eat >= philo->par->time_to_die)
		{
			print_msg(philo, 5);
			exit(1);
		}
		if (philo->par->n_meals > 0 && philo->is_put == 1
			&& philo->eaten_meals >= philo->par->n_meals)
			exit(0);
		usleep(90);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	philo->last_eat = give_time();
	pthread_create(&philo->th, NULL, &thread_watcher, (void *)philo);
	while (1)
	{
		take_forks(philo);
		put_forks(philo);
		print_msg(philo, 4);
	}
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->par->forks);
	print_msg(philo, 1);
	sem_wait(philo->par->forks);
	philo->is_put = 0;
	print_msg(philo, 1);
	print_msg(philo, 2);
	n_sleep(philo->par->time_to_eat);
	philo->last_eat = give_time();
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->par->forks);
	sem_post(philo->par->forks);
	philo->is_put = 1;
	print_msg(philo, 3);
	n_sleep(philo->par->time_to_sleep);
}
