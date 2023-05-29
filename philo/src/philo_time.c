/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:40:10 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/02 15:36:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
