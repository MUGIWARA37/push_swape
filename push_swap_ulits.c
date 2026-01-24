/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ulits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <rhlou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:36:07 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 14:36:07 by rhlou            ###   ########.fr       */
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