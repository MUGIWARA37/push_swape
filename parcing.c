/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:26:31 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/27 18:22:29 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	erreur_nigga(t_stack **stack)
{
	write(2, "Error\n", 6);
	destroy_stack(stack);
	exit(1);
}

static void	arg_handler2(t_stack **stack, char **split)
{
	int		i;
	long	nbr;

	i = 0;
	while (split[i])
	{
		if (!split[i][0] || !av_is_num(split[i]))
		{
			free_split(split);
			erreur_nigga(stack);
		}
		nbr = ft_atoi(split[i]);
		if (!check_number(nbr) || is_belongs(*stack, nbr))
		{
			free_split(split);
			erreur_nigga(stack);
		}
		fill_stack(stack, (int)nbr);
		i++;
	}
}

void	arg_handler(t_stack **stack, char **av)
{
	int		i;
	char	**split;

	if (!av || !*av)
		return ;
	i = 0;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split)
			erreur_nigga(stack);
		arg_handler2(stack, split);
		free_split(split);
		i++;
	}
	assign_index(stack);
}
