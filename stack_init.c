/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:22:22 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/25 21:47:49 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int  check_number(long nbr)
{
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        write(1, "ERROR\n", 6);
        return (0);
    }
    return (1);
}

static int  append_node(t_stack **stack, long nbr)
{
    t_stack *tmp;

    if (!check_number(nbr))
        return (0);
    if (IsBelongs(*stack, nbr))
    {
        write(1, "ERROR\n", 6);
        return (0);
    }
    tmp = *stack;
    if (!tmp)
    {
        *stack = creat_node(nbr);
        if (!*stack)
            return (0);
        return (1);
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = creat_node(nbr);
    if (!tmp->next)
        return (0);
    return (1);
}
void assign_index(t_stack **stack)
{
    t_stack *tmp1;
    t_stack *tmp2;
    int i;

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


void    stack_init(t_stack **stack, char **av)
{
    int     i;
    long    nbr;

    *stack = NULL;
    i = 0;
    while (av[i])
    {
        nbr = ft_atoi(av[i]);
        if (!append_node(stack, nbr))
        {
            Destroy_stack(stack);
            return ;
        }
        i++;
    }
    assign_index(stack);
}
