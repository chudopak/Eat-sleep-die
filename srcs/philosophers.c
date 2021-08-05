#include "../philosophers.h"

bool	is_philo_alive(t_all *all, int i)
{
	if (all->philosopher[i].time_to_die < get_current_time(all->start_time))
	{
		pthread_mutex_lock(&all->right_to_write);
		printf("%ld\tPhilosopher %d is dead\n",
			get_current_time(all->start_time), i + 1);
		return (true);
	}
	return (false);
}

void	threads_monitoring(t_all *all)
{
	int	i;
	int	philo_with_max_meal_intake;

	philo_with_max_meal_intake = 0;
	while (1)
	{
		i = 0;
		while (i < all->input.number_of_philo)
		{
			pthread_mutex_lock(&all->philosopher[i].right_to_eat);
			if (all->philosopher[i].eaten_meals == all->input.meal_intake)
				philo_with_max_meal_intake++;
			if (is_philo_alive(all, i))
				return ;
			pthread_mutex_unlock(&all->philosopher[i].right_to_eat);
			i++;
		}
		if (philo_with_max_meal_intake == all->input.meal_intake)
		{
			pthread_mutex_lock(&all->right_to_write);
			return ;
		}
	}
}

void	*eat_sleep_think(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		//printf("Philo Says hi %d\n", philo->id);
		//usleep(1000000);
		if (philo->all->input.meal_intake
			|| philo->eaten_meals < philo->all->input.meal_intake)
		{
			take_forks(philo);
			eat(philo);
			think(philo);
		}
	}
	return (NULL);
}

void	start_threads(t_all *all)
{
	int			i;
	pthread_t	thread_id;

	i = 0;
	while (i < all->input.number_of_philo)
	{
		if (pthread_create(&thread_id, NULL,
				eat_sleep_think, (void *)(all->philosopher + i)))
		{
			pthread_mutex_lock(&all->right_to_write);
			printf("Could not create a thread for %d philosopher\n", i);
			return ;
		}
		pthread_detach(thread_id);
		i++;
	}
	threads_monitoring(all);
}

int	main(int ac, char **av)
{
	t_all	all;

	set_all(&all, ac - 1, av + 1);
	if (all.error_status == false)
		start_threads(&all);
	//printf("%ld\n", all.start_time);
	//printf("ERROR STATUS %d\n", all.error_status);
	free_all(&all);
	//while (1);
	return (0);
}
