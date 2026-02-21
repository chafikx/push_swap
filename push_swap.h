#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					push_cost;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

long			ft_atol(const char *str);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			init_stack_a(t_stack_node **a, char **argv, int is_allocated);
void			append_node(t_stack_node **stack, int n);

void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv);
void			free_matrix(char **argv);

int				is_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
void			set_current_position(t_stack_node *stack);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			cost_analysis_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

void			prep_for_push(t_stack_node **s, t_stack_node *n, char name);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif