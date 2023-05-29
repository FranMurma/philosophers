/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:21 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/25 18:21:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Chequea para cada filosofo si ha pasado mas tiempo del adjudicado 
// para cada comida. Si es asi, sube data->death, lockea mute_death,
// mute_print y mute_forks
int	ft_die(t_data *data)
{
	int	c;

	c = 0;
	while (c < data->philo_nb)
	{
		if (data->time_die < (long long int)((ft_get_current_time()
				- data->time_start) - data->philo[c].last_meal))
		{
			pthread_mutex_lock(&data->mute_death);
			ft_print_death(data, c + 1, "is dead.\n");
			data->death++;
			return (0);
		}
		c++;
	}
	return (1);
}

// Chequeamos para cada filosofo -> Si pasa mas tiempo 
// del limite desde la ultima comida, data->death++;	
int	ft_routine_finish(t_data *data)
{
	int	c;
	int	out;

	c = 0;
	out = 0;
	while (c < data->philo_nb && data->times_must_eat > 0)
	{
		if (data->philo[c].need_eat >= data->times_must_eat)
			out++;
		c++;
	}
	if (out >= data->philo_nb)
	{
		data->death++;
		return (0);
	}
	return (1);
}

// Funcion que chequea si hemos terminado. Un check va a la 
// funcion que comprueba cuantas veces hemos comido y 
// si ya hemos cumplido (ft_routine_finish).
// Por otra parte, va a la funcion que chequea para cada filosofo
// cuando va a comer, si ha pasado mas tiempo del que tiene adjudicado 
// para cada comida (ft_die). 
// Si cualquiera tiene retorno 0, sale (break). 
void	ft_check_if_finish(t_data *data)
{
	while (42)
	{
		if (ft_routine_finish(data) == 0)
		{
			pthread_mutex_lock(&data->mute_print);
			ft_print_end(data,
				"All philosophers have eaten all!!");
			break ;
		}
		if (ft_die(data) == 0)
			break ;
	}
}

int	ft_create_pthread(t_data *data)
{
	pthread_t	*pthread;
	int			c;

	c = 0;
	pthread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_nb);
	if (!pthread)
		return (-1);
	while (c < data->philo_nb)
	{
		if (pthread_create(&pthread[c], NULL,
				&ft_start_routine, &data->philo[c]) != 0)
			return (-1);
		data->philo[c].last_meal = ft_get_current_time();
		c++;
	}
	ft_check_if_finish(data);
	pthread_mutex_unlock(&data->mute_print);
	c = 0;
	while (c < data->philo_nb)
	{
		pthread_join(pthread[c], NULL);
		c++;
	}
	free(pthread);
	return (0);
}
