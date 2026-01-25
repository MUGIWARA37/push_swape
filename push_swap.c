/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:09:59 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/25 21:25:33 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include "push_swap.h"
void        printf_stack(t_stack *s)
{
    while (s)
    {
        printf("%d\n",s->data);
        s = s->next;
    }
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    stack_init(&a,av + 1);
    if(ac == 2)
        free_split(av);
    radix_sort(&a , &b);
    printf_stack(a);
    Destroy_stack(&a);
    Destroy_stack(&b);
}
