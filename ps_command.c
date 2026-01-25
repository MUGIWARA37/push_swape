/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:14:49 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/25 22:36:29 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void     swap_f2(t_stack **stack) // swap first 2 elements
{
    t_stack     *tmp;

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}

void    double_swap(t_stack **stack_a , t_stack **stack_b)
{
    if(stack_a == stack_b)
    {
        swap_f2(stack_a);
        return;
    }
    swap_f2(stack_a);
    swap_f2(stack_b);
}

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

void    double_rotate_mn(t_stack **a,t_stack **b)
{
    if(a == b)
    {
        ra(a);
        return ;
    }
    ra(a);
    ra(b);
}

void    reverse_ra(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void      double_rrr_mf(t_stack    **a,t_stack    **b)
{
    if(a == b)
    {
        reverse_ra(a);
        return ;
    }
    reverse_ra(a);
    reverse_ra(b);
}