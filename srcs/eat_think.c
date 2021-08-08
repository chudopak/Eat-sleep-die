#include "../philosophers.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->first_taken_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\tPhilo %d has taken first fork\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(philo->right_to_write);
	pthread_mutex_lock(philo->second_taken_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\tPhilo %d has taken second fork\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(philo->right_to_write);
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_to_eat);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\tPhilo %d is eating\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(philo->right_to_write);
	philo->eaten_meals++;
	philo->time_to_die = get_current_time(philo->all->start_time)
		+ philo->all->input.time_to_die;
	pthread_mutex_unlock(&philo->right_to_eat);
	_usleep(philo->all->input.time_to_eat, philo->all->start_time);
	pthread_mutex_unlock(philo->second_taken_fork);
	pthread_mutex_unlock(philo->first_taken_fork);
}

void	think(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld\tPhilo %d is thinking\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(philo->right_to_write);
}
