/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:19:56 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 14:49:40 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h" 

/***
 * Introducimos los datos de argv en t_data *data
 * */
int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->philo_nb = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->times_must_eat = ft_atoi(argv[5]);
		if (data->times_must_eat == 0)
		{
			printf("Error\nNothing to eat\n");
			free(data);
			return (-1);
		}
	}
	if (data->philo_nb <= 0 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0)
	{
		printf("Error\nPlease enter right numbers\n");
		free(data);
		return (-1);
	}
	return (0);
}

/***
 * Iniciamos los datos que pueden ser muteados. death y print, normal, 
 * forks es un array, asi que malloc
 ***/
int	ft_init_mutex(t_data *data)
{
	int	c;

	c = 0;
	if (pthread_mutex_init(&data->mute_death, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->mute_print, NULL) != 0)
		return (-1);
	data->mute_forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	while (c < data->philo_nb)
	{
		if (pthread_mutex_init(&data->mute_forks[c], NULL) != 0)
			return (-1);
		c++;
	}
	if (pthread_mutex_init(&data->mute_forks[c], NULL) != 0)
		return (-1);
	return (0);
}

/***
 * Iniciamos los filosofos, cada uno de ellos. Como es un array, malloc.
 * Con el contador asignamos que numero de tenedor corresponde al righ o left
 * de cada filosofo. La ultima comida de cada filosofo es coger en este momento
 * el current time  
 * */
int	ft_init_philo(t_data *data)
{
	int	c;

	c = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * (data->philo_nb));
	if (!data->philo)
	{
		return (-1);
		free(data->philo);
	}
	while (c < data->philo_nb)
	{
		data->philo[c].name = c + 1;
		data->philo[c].left_fork = c;
		if (c != 0)
			data->philo[c].right_fork = c - 1;
		data->philo[c].data = data;
		data->time_start = ft_get_current_time() + (data->philo_nb * 8);
		c++;
	}
	data->philo[0].right_fork = c -1;
	return (0);
}

int	ft_init_all(t_data *data, int argc, char **argv)
{
	if (ft_init_data(data, argc, argv) != 0)
		return (-1);
	if (ft_init_mutex(data) != 0)
		return (-1);
	if (ft_init_philo(data) != 0)
		return (-1);
	return (0);
}
