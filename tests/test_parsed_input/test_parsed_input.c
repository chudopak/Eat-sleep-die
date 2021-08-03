#include "../../philosophers.h"

int		main(int ac, char **av)
{
	t_input	input;

	set_input(&input, ac - 1, av + 1);
	if (input.is_valid_input)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	printf("Philo's Number - %d\n", input.number_of_philo);
	printf("Time to die - %d\n", input.time_to_die);
	printf("Time to eat - %d\n", input.time_to_eat);
	printf("Time to sleep - %d\n", input.time_to_sleep);
	printf("Number of times to eat - %d\n", input.nb_of_times_to_eat);
	return (0);
}