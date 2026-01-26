/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:00:00 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/26 14:35:47 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	get_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	max = -1;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	rotate_to_top(t_stack **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		while (pos++ < size)
			rrb(b);
	}
}

void	push_chunks(t_stack **a, t_stack **b, int chunk)
{
	int	i;
	int	pushed;
	int	size;

	i = 0;
	pushed = 0;
	size = ft_lstsize(*a);
	while (pushed < size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
			pushed++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b);
			i++;
			pushed++;
		}
		else
			ra(a);
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	int	pos;

	while (*b)
	{
		pos = get_max_pos(*b);
		rotate_to_top(b, pos);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;

	size = ft_lstsize(*a);
	if (size <= 100)
		chunk = 20;
	else
		chunk = 45;
	push_chunks(a, b, chunk);
	push_back(a, b);
}
