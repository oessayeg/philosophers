/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:29:34 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:37:51 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_struct(int argc, char **argv, t_params *par)
{
	par->n_philo = ft_atoi(argv[1]);
	par->time_to_die = ft_atoi(argv[2]);
	par->time_to_eat = ft_atoi(argv[3]);
	par->time_to_sleep = ft_atoi(argv[4]);
	par->n_meals = 0;
	par->sim_start = give_time();
	if (argc == 6)
		par->n_meals = ft_atoi(argv[5]);
	par->forks = malloc(sizeof(pthread_mutex_t) * par->n_philo);
	if (par->forks == NULL)
	{
		write(2, "Malloc Failed !\n", 16);
		return (1);
	}
	if (pthread_mutex_init(&par->print_mutex, NULL) != 0)
	{
		write(2, "Pthread_mutex_init Failed !\n", 28);
		return (1);
	}
	return (0);
}

t_philo	*init_philo_struct(t_params *par)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * par->n_philo);
	if (philos == NULL)
	{
		write(2, "Malloc Failed !\n", 16);
		return (NULL);
	}
	i = -1;
	while (++i < par->n_philo)
	{
		philos[i].philo_id = i + 1;
		philos[i].left_fork = (i + 1) % par->n_philo;
		philos[i].right_fork = i;
		philos[i].last_eat = give_time();
		philos[i].eaten_meals = 0;
		philos[i].rules = par;
		if (pthread_mutex_init(&par->forks[i], NULL) != 0)
		{
			write(2, "Pthread_mutex_init Failed !\n", 28);
			return (NULL);
		}
	}
	return (philos);
}
