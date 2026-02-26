/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:55:42 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/02/26 23:04:57 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **s, t_stack_node *n, char name)
{
	while (*s != n)
	{
		if (name == 'a')
		{
			if (n->current_pos <= (stack_len(*s) / 2))
				ra(s);
			else
				rra(s);
		}
		else if (name == 'b')
		{
			if (n->current_pos <= (stack_len(*s) / 2))
				rb(s);
			else
				rrb(s);
		}
		set_current_position(*s);
	}
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->current_pos <= (stack_len(*b) / 2)
		&& cheapest_node->target_node->current_pos <= (stack_len(*a) / 2))
	{
		while (*b != cheapest_node && *a != cheapest_node->target_node)
		{
			rr(a, b);
			set_current_position(*a);
			set_current_position(*b);
		}
	}
	else if (cheapest_node->current_pos > (stack_len(*b) / 2)
		&& cheapest_node->target_node->current_pos > (stack_len(*a) / 2))
	{
		while (*b != cheapest_node && *a != cheapest_node->target_node)
		{
			rrr(a, b);
			set_current_position(*a);
			set_current_position(*b);
		}
	}
	prep_for_push(a, cheapest_node->target_node, 'a');
	prep_for_push(b, cheapest_node, 'b');
	pa(a, b);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	while (len > 3)
	{
		pb(b, a);
		len--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		set_current_position(*a);
		set_current_position(*b);
		set_target_b(*a, *b);
		cost_analysis_b(*a, *b);
		set_cheapest(*b);
		move_b_to_a(a, b);
	}
	set_current_position(*a);
	prep_for_push(a, find_smallest(*a), 'a');
}
