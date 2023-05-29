/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:55 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 19:30:31 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h" 

void	ft_print_values_errors(t_philo *philo)
{
	printf("Please, follow the rules:\nPhilosophers: 1 or more\n");
	printf("Time to die: at least 60 ms\nTime to eat: at least 60 ms\n");
	printf("Time to sleep: at least 60 ms\nPlease, use correct parameters\n");
	free(philo);
}

/***
 * Introducimos los datos de argv en t_philo *philo
 * Ojo a philo->time_start: durante un lapso de tiempo, el current_time sera 
 * menor que el time_start, a tener en cuenta en las funciones en que se tenga
 * en cuenta el tiempo
 * */

int	ft_init_philo(t_philo *philo, int argc, char **argv)
{
	philo->philo_nb = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if ((philo->philo_nb < 1) || (philo->time_die < 60) || (philo->time_eat
			< 60) || (philo->time_sleep < 60))
	{
		ft_print_values_errors(philo);
		return (-1);
	}
	if (argc == 6)
		philo->times_must_eat = ft_atoi(argv[5]);
	else if (argc == 5)
		philo->times_must_eat = -1;
	philo->name = 0;
	philo->time_start = ft_get_current_time() + (60 * philo->philo_nb);
	philo->time_start = philo->time_start;
	philo->last_meal = philo->time_start;
	return (0);
}

/***
 * Iniciamos los semaforos de los recursos limitados:
 * sem_unlink("Nombre del recurso");
 * Lo guardamos en una estructura t_philo:
 * philo->print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
 * Donde creamos el semaforo sem_print, garantizamos que es EXCLusivo
 * para este proceso, damos permisos para que solo escriba el propietario
 * Y le decimos que solo puede acceder 1 a ese elemento
 ***/
int	ft_init_sems(t_philo *philo)
{
	sem_unlink("sem_print");
	sem_unlink("sem_eat");
	sem_unlink("sem_fork");
	sem_unlink("sem_stop");
	philo->print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	philo->fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644,
			philo->philo_nb);
	philo->eat = sem_open("sem_eat", O_CREAT | O_EXCL, 0644, 1);
	if (philo->print == SEM_FAILED || philo->fork == SEM_FAILED)
	{
		printf("Error\nBad semaphores\n");
		return (-1);
	}
	if (philo->eat == SEM_FAILED)
	{
		printf("Error\nBad semaphores\n");
		return (-1);
	}
	return (0);
}

int	ft_init_all(t_philo *philo, int argc, char **argv)
{
	if (ft_init_philo(philo, argc, argv) != 0)
		return (-1);
	if (ft_init_sems(philo) != 0)
		return (-1);
	return (0);
}
