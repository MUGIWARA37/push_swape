/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <rhlou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:22:22 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 14:22:22 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void stack_init(t_stack **stack, char **av)
{
    int i;
    t_stack *tmp;

    i = 1;
    *stack = creat_node(ft_atoi(av[0]), 0);
    if (!*stack)
        return;
    tmp = *stack;
    while (av[i])
    {
        tmp->next = creat_node(ft_atoi(av[i]), i);
        if (!tmp->next)
            return;
        tmp = tmp->next;
        i++;
    }
}
