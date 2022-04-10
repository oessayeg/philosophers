/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_waiting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:08:42 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:43:00 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	wait_processes(t_philo *philo)
{
	int	i;
	int	stat;
	int	t;

	t = -1;
	i = -1;
	while (++i < philo[0].par->n_philo)
	{
		waitpid(-1, &stat, 0);
		if (stat != 0)
		{
			while (++t < philo[0].par->n_philo)
				kill(philo[i].process_id, SIGINT);
			return ;
		}
	}
	print_msg(&philo[0], 6);
	return ;
}
