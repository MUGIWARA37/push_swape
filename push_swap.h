/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:07:35 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/26 14:37:05 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int     data;
    int     index;
    struct  s_stack     *next;
}           t_stack;

// inserting functiong and helper functions 
void    stack_init(t_stack **stack ,char **av);
int     is_belongs(t_stack *stack , int key);
void    fill_stack(t_stack **stack, int data);
void    free_split(char **av);
void    destroy_stack(t_stack **stack);
char			**ft_split(char const *s, char c);
t_stack     *creat_node(int data);
long	ft_atoi(const char *str);
int	ft_lstsize(t_stack *lst);

// sorting algo and moves function
void	chunk_sort(t_stack **a, t_stack **b);
void    radix_sort(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **stack);
void    rb(t_stack **stack);
void    rrb(t_stack **stack);

// split helpers 
 int		numstring(char const *s1, char c);
 int		numchar(char const *s2, char c, int i);
 char		**freee(char const **dst, int j);
 char		**affect(char const *s, char **dst, char c, int l);




#endif