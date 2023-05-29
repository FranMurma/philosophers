/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_close_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:44:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/24 15:45:21 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	ft_delete_sems(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->eat);
}
