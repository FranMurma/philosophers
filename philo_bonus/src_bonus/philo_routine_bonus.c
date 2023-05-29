/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:13:33 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 19:30:28 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/****
 * Cogemos estos recursos:
 * -eat, que tiene solo 1 elemento. Como en todas las rutinas de comer el 
 *  primer paso es bloquear eat, ningun otro filosofo podra coger un tenedor
 *  hasta que el que bloquea eat agarre otro
 * ** */
void	ft_eat(t_philo *philo)
{
	int	name;

	name = philo->name;
	sem_wait(philo->eat);
	sem_wait(philo->fork);
	sem_wait(philo->print);
	ft_print_action(philo, name, "has taken a fork.");
	sem_wait(philo->fork);
	ft_print_action(philo, name, "has taken another fork.");
	ft_print_action(philo, name, "is eating");
	sem_post(philo->print);
	sem_post(philo->eat);
	philo->last_meal = ft_get_current_time() - philo->time_start;
	ft_usleep(philo->time_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
	if (philo->argc6 == 1)
		philo->times_must_eat--;
	if (philo->times_must_eat == 0 && philo->argc6 == 1)
		exit (0);
}

void	ft_sleep_think(t_philo *philo)
{
	int	name;

	name = philo->name;
	sem_wait(philo->eat);
	sem_wait(philo->print);
	ft_print_action(philo, name, "is sleeping.");
	sem_post(philo->print);
	sem_post(philo->eat);
	ft_usleep(philo->time_sleep);
	sem_wait(philo->eat);
	sem_wait(philo->print);
	ft_print_action(philo, name, "is thinking.");
	sem_post(philo->print);
	sem_post(philo->eat);
}

/****
 * Funcion para un solo filosofo. Toma un tenedor y muere.
 ****/
int	ft_one_philo(t_philo *philo)
{
	if (philo->philo_nb == 1)
	{
		sem_wait(philo->eat);
		sem_wait(philo->fork);
		sem_wait(philo->print);
		ft_print_action(philo, philo->name, "has taken a fork");
		philo->time_die = ft_time_from_last_meal(philo);
		sem_post(philo->print);
	}
	return (0);
}

/* ***
 * Recibimos la informacion de philo, mandado por ft_start_routine.
 * la funcion rutina de a la que llama pthread solo puede ser
 * void   *rutina(void *loquesea). Por tanto, hay que castear a t_philo
 * lo que recibimos
 * Mientras que el tiempo actual aun no es el tiempo de salida 
 * (time_start, ver ft_init_philo) vamos usleepeando en fracciones de 1.
 * Mientras hay comida o si el concepto comida no existe, nos metemos en
 * un bucle de comer, dormir, pensar.
 ** *****/
void	*ft_routine(void *cast_philo)
{
	t_philo	*philo;

	philo = (t_philo *)cast_philo;
	while (philo->time_start > ft_get_current_time())
		ft_usleep(5);
	philo->last_meal = philo->time_start;
	if (ft_one_philo(philo) == 1)
		exit(0);
	while ((philo->times_must_eat > 0) || (philo->times_must_eat == -1))
	{
		ft_eat(philo);
		ft_sleep_think(philo);
	}
	if (philo->times_must_eat == 0)
		exit (1);
	return (NULL);
}
