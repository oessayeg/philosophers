/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:24 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/08 17:55:12 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	*par;
	t_philo		*philo;

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	par = malloc(sizeof(t_params));
	if (par == NULL)
		return (m_fail());
	if (init_struct(argc, argv, par))
		return (EXIT_FAILURE);
	philo = init_philo_struct(par);
	if (philo == NULL)
		return (EXIT_FAILURE);
	if (init_threads(philo))
		return (EXIT_FAILURE);
	return (0);
}
