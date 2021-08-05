#include "../philosophers.h"

int	main(int ac, char **av)
{
	t_all	all;

	set_all(&all, ac - 1, av + 1);
	if (all.input.is_valid_input == true || all.fork)
		;
	return (0);
}
