#ifndef STRUCT_H
#define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>


typedef struct S_philo
{
	int		id;
	int		nb_ate;
	int		last_meal;
	struct S_all	*backup;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	
}	t_philo;

typedef struct S_rules
{
	int	death_time;
	int	nb_eats;
	int	sleep_time;
	int	eat_time;
	int	n_philo;
}	t_rules;

typedef struct S_all
{
	int		is_dead;
	t_rules  	*rules;
	t_philo		*philo;
	pthread_t	*threads;
}	t_all;

int	create_threads(t_all *all);

#endif
