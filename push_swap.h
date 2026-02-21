#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}	t_stack_node;

int stack_len(t_stack_node *stack);
void set_current_position(t_stack_node *stack);
long	ft_atol(const char *str);

#endif