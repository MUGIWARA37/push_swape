/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_number_hundler_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:41:53 by rhlou             #+#    #+#             */
/*   Updated: 2026/02/01 12:21:03 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_num(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		is_two(a);
	else if (size == 3)
		is_three(a);
	else
		is_more(a, b);
	destroy_stack(a);
	destroy_stack(b);
	exit(0);
}
