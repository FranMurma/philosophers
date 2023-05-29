/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:49:53 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 19:17:24 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/*****
 * Recibe el pid del ultimo proceso del check_if_dead. 
 * Compara el pid recibido con los pids de todos los otros procesos, y elimina 
 * todos menos el recibido (que ha muerto antes).
 ****/
int	ft_kill_them_all(t_philo *philo, int pid)
{
	int	c;

	c = 1;
	while (c <= philo->philo_nb)
	{
		if (philo->pid[c] != pid)
			kill(philo->pid[c], SIGKILL);
		c++;
	}
	return (1);
}

/*****
 *  waitpid() en C espera a que un proceso hijo termine su ejecución 
 *  y da la información sobre su estado de finalización.
 *  pid = numero pid del proceso hijo que ha terminado.
 *  -1 = la función espera por cualquier proceso hijo.
 *  status guarda cual ha sido el codigo de salida (return o exit, 0 o 1) 
 *  de ese hijo. 
 *  Si el wexitsatus es = 0, el proceso hijo ha terminado correctamente.
 *  Si wexistatus(status) = 1, el proceso hijo ha experimentado algún 
 *  tipo de error.
 *  Cuando sale (o porque un hijo se ha muerto (wexitstatus 1) o porque 
 *  todos han acabado (wexitstatus 0)),  enviamos el pid del ultimo hijo 
 *  a ft_kill_all(data, pid) (salida 1 si ha muerto, 0 si todos han terminado)
 *******/
int	ft_check_if_dead(t_philo *philo)
{
	int		c;
	pid_t	pid;
	int		status;

	c = 1;
	while (c <= philo->philo_nb)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (WEXITSTATUS(status) == 1)
			break ;
		if (WEXITSTATUS(status) == 0)
			c++;
	}
	ft_kill_them_all(philo, pid);
	if (c == philo->philo_nb + 1)
		return (0);
	return (1);
}

/*****
 * Funcion que inicia la rutina. Necesitamos un pthread para que los hijos 
 * puedan comunicarse. Creamos el phread, comprobamos que no haya un error.
 * Metemos la rutina que chequea constantemente la muerte: mientras quede 
 * comida para comer, comprobamos que no haya un muerto 
 * (time->die < ft_time_from_last_meal). 
 * Por otra lado, en otra funcion vamos dsminuyendo  en cada filosofo las 
 * veces que tiene que comer (times_must_eat); como tenemos un times_must_eat
 * para cada filosofo, no hace falta guardar la informacion en otra estructura.
 ****/
int	ft_start_routine(t_philo *philo, int nb)
{
	pthread_t		check;
	long long int	time_d;

	philo->name = nb;
	if (pthread_create(&check, NULL, ft_routine, philo) != 0)
	{
		sem_wait(philo->print);
		printf("Error.\nBad pthreads\n");
		sem_close(philo->print);
		exit (0);
	}
	while (philo->times_must_eat < 0)
	{
		if (philo->time_die < ft_time_from_last_meal(philo))
		{
			sem_wait(philo->print);
			time_d = ft_get_current_time() - philo->time_start;
			ft_print_death(philo, time_d, philo->name, "HAS DIED!!");
			exit (1);
		}
	}
	pthread_join(check, NULL);
	return (0);
}

/***
 * Creamos un malloc de un pid_t por cada filosofo.
 * Creamos forks, un  hijo por cada filosofo, usando el contador. 
 * el pid = fork(); la devolucion puede ser > 0, == 0 o <0.
 * Si es > 0, es que es el padre (toma el pid de un hijo, que siempre 
 * es un numero positivo) y sumamos 1 al contador.
 * Si la devolucion es 0, es un hijo creado por su padre, lanzamos la rutina.
 * Si la devolucion es < 0, es un error. Salimos.
 * ***/
int	ft_start_process(t_philo *philo)
{
	int	c;

	c = 1;
	philo->pid = malloc(sizeof(pid_t) * philo->philo_nb);
	if (!philo->pid)
		return (-1);
	while (c <= philo->philo_nb)
	{
		philo->pid[c] = fork();
		if (philo->pid[c] > 0)
			c++;
		else if (philo->pid[c] == 0)
		{
			ft_start_routine(philo, c);
			break ;
		}
		else
//		else if (philo->pid[c] < 0)
			exit (1);
	}
	if (ft_check_if_dead(philo) == 0)
		printf("All philosophers have finished their routine\n");
	return (0);
}
