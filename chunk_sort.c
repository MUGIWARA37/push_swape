/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:02:20 by rhlou             #+#    #+#             */
/*   Updated: 2026/02/02 11:34:30 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *stack)
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

static void	rotate_to_top(t_stack **b, int pos)
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

static void	push_chunks(t_stack **a, t_stack **b, int chunk)
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

static void	push_back(t_stack **a, t_stack **b)
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
	int	chunk_size;

	size = ft_lstsize(*a);
	if (size <= 20)
	{
		chunk_size = 5;
	}
	else if (size <= 100)
		chunk_size = 13;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	push_back(a, b);
}
