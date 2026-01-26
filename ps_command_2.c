/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:34:00 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/26 12:34:33 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "push_swap.h"

void    rra(t_stack **stack)
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
    write(1,"rra\n",4);
}

void    rrb(t_stack **stack)
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
    write(1,"rrb\n",4);
}
