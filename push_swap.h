/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <rhlou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:07:35 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 14:07:35 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int     data;
    int     index;
    struct  s_stack     *next;
}           t_stack;

void    stack_init(t_stack **stack ,char **av);

#endif