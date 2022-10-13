#include "struct.h"



unsigned int	ft_atoui(char *s)
{
	unsigned int	n;

	n = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	while (*s <= '9' && *s >= '0')
	{
		n *= 10;
		n += *s - 48;
		s++;
	}
	return (n);
}

int	init_rules(t_rules *rules, int ac, char **av)
{
	rules->n_philo = ft_atoui(av[1]);
	rules->death_time = ft_atoui(av[2]);
	rules->eat_time = ft_atoui(av[3]);
	rules->sleep_time = ft_atoui(av[4]);
	if (ac == 6)
		rules->nb_eats = ft_atoui(av[5]);
	return (0);
}

int	init_philo(t_philo *philo, t_all *all)
{
	
	int	i;
	
	i = 0;
	while (i < all->rules->n_philo)
	{
		philo[i].id = i;
		philo[i].nb_ate = 0;
		philo[i].last_meal = 0;
		philo[i].backup = all;
		pthread_mutex_init(&philo[i].right_fork, NULL);
		i++;
	}
	i = 0;
	while (i < all->rules->n_philo)
	{
		if (philo[i].id == all->rules->n_philo - 1)
			philo[i].left_fork = &philo[0].right_fork;
		else
			philo[i].left_fork = &philo[i + 1].right_fork;
		i++;
	}
	return (0);
}

int	init_threads(t_all *all)
{
	all->threads = malloc(sizeof(pthread_t) * all->rules->n_philo);
	if (!all->threads)
		return (1);
	return (0);
}

int	__init__(t_all *all, int ac, char **av)
{
	t_philo *philo;
	t_rules *rules;	
	int	i;	

	rules = malloc(sizeof(t_rules));
	init_rules(rules, ac, av);
	all->rules = rules;
	philo = malloc(sizeof(t_philo) * rules->n_philo);
	init_philo(philo, all);
	all->philo = philo;
	init_threads(all);
	all->is_dead = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac < 5 || ac > 6)
		return(1);
	__init__(&all, ac, av);
	create_threads(&all);	
	return (0);
}
