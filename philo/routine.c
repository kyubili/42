#include "struct.h"

// gérer le temps en milisecondes

int	eating(t_philo *philo)
{
	// prend la fork, il affiche 2x, et il mange
	// appeler taking fork
	printf("%d is eating\n", philo->id);
	// ne pas oublier de libérer
	return (0);
}

int	sleeping(t_philo *philo)
{
	// regarder si qqun ou soi meme est mort
	printf("%d is sleeping\n", philo->id);
	return (0);
}

int	taking_fork(t_philo *philo)
{
	printf("%d is taking a fork\n", philo->id);
	return (0);
}

void	*routine(void *var)
{
	t_philo	*philo;
	t_all 	*all;

	philo = (t_philo *)var;
	all = philo->backup;
	if (philo->id % 2 == 0)
		usleep(1500);
	//while (!all->is_dead)
	//{
		eating(philo);
		sleeping(philo);
		printf("%d is thinking\n", philo->id);
	//}
	return (NULL);
}

int	create_threads(t_all *all)
{
	int	i;
	t_philo *philos;

	philos = all->philo;	
	i = 0;
	while (i < all->rules->n_philo)
	{
		//printf("%d\n", philos[i].id);
		pthread_create(&all->threads[i], NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < all->rules->n_philo)
	{
		pthread_join(all->threads[i], NULL);
		i++;
	}
	return (0);
}

