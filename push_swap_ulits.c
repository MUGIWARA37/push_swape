/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ulits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:36:07 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 18:47:13 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

t_stack     *creat_node(int data, int index)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return NULL;
    node->data = data;
    node->index = index;
    node->next = NULL;
    return (node);
}

int     IsBelongs(t_stack *stack , int key)
{
    t_stack     *tmp;

    if(!stack)
        return (0);
    tmp = stack ;
    while (tmp)
    {
        if(tmp->data == key)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    Destroy_stack(t_stack **stack)
{
    t_stack *tmp;

    if(!stack || !*stack)
        return ;
    while(*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

void       free_split(char **av)
{
    int i;
    if(!av)
        return ;
    i  = 0;
    while (av[i])
        free(av[i++]);
    free(av);
}

void    fill_stack(t_stack **stack, int data , int index)
{
    t_stack    *new;
    t_stack    *tmp;
    
    new = creat_node(data , index);
    if(!new)
        return ;
    if(!*stack)
    {
        *stack = new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}