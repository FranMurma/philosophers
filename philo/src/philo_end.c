/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:00:45 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/25 16:02:11 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_end(t_data *data)
{
	int	c;

	c = 0;
	pthread_mutex_unlock(&data->mute_death);
	pthread_mutex_unlock(data->mute_forks);
	pthread_mutex_destroy(&data->mute_death);
	pthread_mutex_destroy(&data->mute_print);
	while (c < data->philo_nb)
	{
		pthread_mutex_destroy(&data->mute_forks[c]);
		c++;
	}
	free(data->philo);
	free(data->mute_forks);
	free(data);
}
