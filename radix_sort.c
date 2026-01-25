/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:52:35 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/25 21:45:17 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "push_swap.h"

int get_max_bits(t_stack *stack)
{
    int max = 0;
    int bits = 0;

    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void process_bit_pass(t_stack **a, t_stack **b, int bit)
{
    int size = 0;
    int j;
    t_stack *tmp = *a;

    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    j = 0;
    while (j < size)
    {
        if (((*a)->index >> bit) & 1)
            ra(a);
        else
            pb(a, b);
        j++;
    }
    while (*b)
        pa(a, b);
}

void radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int max_bits;

    if (!a || !*a)
        return ;
    max_bits = get_max_bits(*a);
    i = 0;
    while (i < max_bits)
    {
        process_bit_pass(a, b, i);
        i++;
    }
}

