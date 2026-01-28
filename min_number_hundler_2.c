/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_number_hundler_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:41:53 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/28 10:42:20 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_num(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		is_2(a);
	else if (size == 3)
		is_3(a);
	else
		is_4_5(a, b);
	destroy_stack(a);
	destroy_stack(b);
	exit(0);
}
