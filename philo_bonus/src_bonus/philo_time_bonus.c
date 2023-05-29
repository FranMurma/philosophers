/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:40:10 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/18 20:06:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/***
 *Funcion para obtener el tiempo actual
 ***/
long long int	ft_get_current_time(void)
{
	struct timeval	time;
	long long int	current;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current);
}

/****
 * Funcion para usar el usleep (que es poco preciso para tiempos pequenos)
 * en relacion con el current time
 ****/
void	ft_usleep(int nbr)
{
	long long int	c;

	c = ft_get_current_time();
	while (nbr > ft_get_current_time() - c)
	{
		usleep(nbr / 2);
	}
}

long long int	ft_time_from_last_meal(t_philo *philo)
{
	long long int	time_d;

	time_d = ft_get_current_time() - philo->time_start - philo->last_meal;
	return (time_d);
}
