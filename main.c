#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	char			**args;
	int				is_allocated;

	a = NULL;
	is_allocated = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_allocated = 1;
	}
	else
		args = argv + 1;
	init_stack_a(&a, args, is_allocated);
	if (is_allocated)
		free_matrix(args);
	if (!is_sorted(a))
	{
		if (a->next != NULL && a->next->next == NULL)
			sa(&a);
		else if (a->next != NULL && a->next->next != NULL && a->next->next->next == NULL)
			sort_three(&a);
	}
	free_stack(&a);
	return (0);
}