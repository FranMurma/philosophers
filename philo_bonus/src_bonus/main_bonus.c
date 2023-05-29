/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:31:51 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 17:07:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	system("clear");
	if (ft_checks(&philo, argc, argv) == -1)
		return (-1);
	if (ft_init_all(&philo, argc, argv) != 0)
		return (-1);
	ft_start_process(&philo);
	ft_delete_sems(&philo);
	return (0);
}
