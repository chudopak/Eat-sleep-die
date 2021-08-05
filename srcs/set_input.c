#include "../philosophers.h"

static bool	validadte_parsed_input(t_input *input, int nb_of_args)
{
	if (input->number_of_philo <= 0 || input->time_to_die <= 0
		|| input->time_to_eat <= 0 || input->time_to_sleep <= 0)
		return (false);
	if (nb_of_args == 5 && input->meal_intake <= 0)
		return (false);
	return (true);
}

void	set_input(t_input *input, int nb_of_args, char **args)
{
	input->is_valid_input = false;
	if (nb_of_args < 4 || 5 < nb_of_args)
	{
		printf("Wrong nnumber of arguments\n");
		return ;
	}
	input->number_of_philo = get_input_value(*args++,
			"Number_of_philosophers MUST be positive");
	input->time_to_die = get_input_value(*args++,
			"Time_to_die MUST be positive");
	input->time_to_eat = get_input_value(*args++,
			"Time_to_eat MUST be positive");
	input->time_to_sleep = get_input_value(*args++,
			"Time_to_sleep MUST be positive");
	if (nb_of_args == 5)
		input->meal_intake = get_input_value(*args,
				"Number_of_times_to_eat MUST be positive");
	else
		input->meal_intake = 0;
	input->is_valid_input = validadte_parsed_input(input, nb_of_args);
}
