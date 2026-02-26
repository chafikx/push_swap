/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:55:09 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/02/26 22:56:54 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest_val;

	if (!stack)
		return (NULL);
	highest_val = INT_MIN;
	highest_node = NULL;
	while (stack)
	{
		if (stack->value > highest_val)
		{
			highest_val = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest_val;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_val = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest_val)
		{
			smallest_val = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
