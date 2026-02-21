#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}

void	init_stack_a(t_stack_node **a, char **argv, int is_allocated)
{
	long	n;
	int		i;
	char	**to_free;

	i = 0;
	to_free = NULL;
	if (is_allocated)
		to_free = argv;
	while (argv[i] != NULL)
	{
		if (error_syntax(argv[i]))
			free_errors(a, to_free);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, to_free);
		if (error_duplicate(*a, (int)n))
			free_errors(a, to_free);
		append_node(a, (int)n);
		i++;
	}
}