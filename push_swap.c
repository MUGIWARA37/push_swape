/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:09:59 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/26 14:37:05 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

void	printf_stack(t_stack *s)
{
	while (s)
	{
		printf("%d\n", s->data);
		s = s->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		write(1, "ERROR_INVALIDE_ARGUMANT\n", 24);
		return (1);
	}
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_init(&a, av);
		free_split(av);
	}
	else
		stack_init(&a, av + 1);
	chunk_sort(&a, &b);
	printf_stack(a);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
