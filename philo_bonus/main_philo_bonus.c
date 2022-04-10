/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:57:30 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:52:06 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_params	*par;
	t_philo		*philo;

	if (check_args(argc, argv))
		return (1);
	par = init_parameters(argc, argv);
	if (par == NULL)
		return (1);
	philo = init_philo(par);
	if (philo == NULL)
		return (1);
	if (init_processes(philo))
		return (1);
	wait_processes(philo);
}
