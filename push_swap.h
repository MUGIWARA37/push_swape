/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:07:35 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/25 21:18:39 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int     data;
    int     index;
    struct  s_stack     *next;
}           t_stack;

void    stack_init(t_stack **stack ,char **av);
int     IsBelongs(t_stack *stack , int key);
void    fill_stack(t_stack **stack, int data);
void    free_split(char **av);
void    Destroy_stack(t_stack **stack);
char			**ft_split(char const *s, char c);
t_stack     *creat_node(int data);



void radix_sort(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **stack);



#endif