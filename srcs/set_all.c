#include "../philosophers.h"

void	assign_exact_forks(t_philosopher *philo,
			pthread_mutex_t *fork, int i1, int i2)
{
	if (i1 % 2 == 0)
	{
		philo[i1].first_taken_fork = &fork[i1];
		philo[i1].second_taken_fork = &fork[i2];
	}
	else
	{
		philo[i1].first_taken_fork = &fork[i2];
		philo[i1].second_taken_fork = &fork[i1];
	}
}

void	assign_forks(t_philosopher *philo,
			pthread_mutex_t *fork, int i, int number_of_philo)
{
	if (i == number_of_philo - 1)
		assign_exact_forks(philo, fork, i, 0);
	else
		assign_exact_forks(philo, fork, i, i + 1);
}

t_philosopher	*set_philosophers(t_all *all)
{
	int				i;
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher) * all->input.number_of_philo);
	if (!philo)
	{
		all->error_status = true;
		return (NULL);
	}
	i = -1;
	while (++i < all->input.number_of_philo)
	{
		if (pthread_mutex_init(&philo[i].right_to_eat, NULL))
		{
			free_philosophers(philo, i);
			return (NULL);
		}
		philo[i].id = i;
		philo[i].all = all;
		philo[i].eaten_meals = 0;
		philo[i].right_to_write = &all->right_to_write;
		philo[i].time_to_die = all->input.time_to_die;
		assign_forks(philo, all->fork, i, all->input.number_of_philo);
	}
	return (philo);
}

pthread_mutex_t	*set_forks(int number_of_philo)
{
	int				i;
	int				init_status;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * number_of_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < number_of_philo)
	{
		init_status = pthread_mutex_init(&fork[i], NULL);
		if (init_status)
		{
			free_forks(fork, i);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

void	set_all(t_all *all, int nb_of_args, char **args)
{
	all->error_status = false;
	set_input(&(all->input), nb_of_args, args);
	if (pthread_mutex_init(&all->right_to_write, NULL))
		all->error_status = true;
	all->start_time = get_start_time();
	all->fork = set_forks(all->input.number_of_philo);
	if (all->fork)
		all->philosopher = set_philosophers(all);
	else
		all->philosopher = NULL;
	if (all->input.is_valid_input == false || !all->fork
		|| !all->philosopher)
		all->error_status = true;
}
