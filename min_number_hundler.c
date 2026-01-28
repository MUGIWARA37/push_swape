/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_number_hundler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:48:53 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/28 10:45:00 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_pos(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	is_2(t_stack **stack)
{
	ra(stack);
}

void	is_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	push_smallest(t_stack **a, t_stack **b, int target)
{
	int	pos;
	int	size;

	size = ft_lstsize(*a);
	pos = find_index_pos(*a, target);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while ((*a)->index != target)
			ra(a);
	}
	else
	{
		while ((*a)->index != target)
			rra(a);
	}
	pb(a, b);
}

void	is_4_5(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 5)
	{
		push_smallest(a, b, 0);
		push_smallest(a, b, 1);
	}
	else
		push_smallest(a, b, 0);
	is_3(a);
	if (size == 5 && (*b)->index < (*b)->next->index)
		sb(b);
	while (*b)
		pa(a, b);
}
