/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:14:49 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/26 12:34:25 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void    pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!b || !*b)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1,"pa\n",3);
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!a || !*a)
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1,"pb\n",3);
}

void    ra(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1,"ra\n",3);
}

void    rb(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1,"rb\n",3);
}


