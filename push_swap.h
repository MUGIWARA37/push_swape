/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:07:35 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/31 10:48:37 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

// inserting functiong and helper functions
int					is_belongs(t_stack *stack, int key);
void				fill_stack(t_stack **stack, int data);
void				free_split(char **av);
void				destroy_stack(t_stack **stack);
t_stack				*creat_node(int data);
int					ft_lstsize(t_stack *lst);
int					is_belongs(t_stack *stack, int key);
void				arg_handler(t_stack **stack, char **av);
int					av_is_num(char *str);
int					check_number(long nbr);
void				assign_index(t_stack **stack);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
int					is_sorted(t_stack **stack);

// case of small number of argumants

void				sort_min_num(t_stack **a, t_stack **b, int size);
void				is_2(t_stack **stack);
void				is_3(t_stack **a);
void				is_4_5(t_stack **a, t_stack **b);
void				push_smallest(t_stack **a, t_stack **b, int target);
int					find_index_pos(t_stack *stack, int index);

// sorting algo and moves function
void	radix_sort(t_stack **a, t_stack **b);
void				chunk_sort(t_stack **a, t_stack **b);
void				sb(t_stack **b);
void				sa(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);

// split helpers
int					numstring(char const *s1, char c);
int					numchar(char const *s2, char c, int i);
char				**freee(char const **dst, int j);
char				**affect(char const *s, char **dst, char c, int l);

#endif