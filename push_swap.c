/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:09:59 by rhlou             #+#    #+#             */
/*   Updated: 2026/02/01 10:16:30 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	arg_handler(&a, av + 1);
	if (is_sorted(&a))
		return (0);
	size = ft_lstsize(a);
	if (size <= 5)
		sort_min_num(&a, &b, size);
	radix_sort(&a , &b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
