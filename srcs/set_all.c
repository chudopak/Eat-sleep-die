#include "../philosophers.h"

void	set_all(t_all *all, int nb_of_args, char **args)
{
	set_input(&(all->input), nb_of_args, args);
}
