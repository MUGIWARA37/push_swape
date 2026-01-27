/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:22:22 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/27 18:20:17 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	av_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '+' || str[i] == '-'))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

int	check_number(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

void	assign_index(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	tmp1 = *stack;
	while (tmp1)
	{
		i = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->data > tmp2->data)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1->index = i;
		tmp1 = tmp1->next;
	}
}
