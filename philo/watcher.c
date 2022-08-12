/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:14:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:50:44 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	check_death_time(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].rules->n_philo)
	{
		if (philo[i].last_eat > 0
			&& give_time() - philo[i].last_eat
			>= philo[i].rules->time_to_die && philo[i].state != 2)
		{
			print_msg(&philo[i], DIE);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meals(t_philo *philo)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < philo[0].rules->n_philo)
	{
		if (philo[i].eaten_meals >= philo[i].rules->n_meals)
			count++;
		i++;
	}
	if (count == philo[0].rules->n_philo)
	{
		print_msg(philo, SIMU);
		return (1);
	}
	return (0);
}
