/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:16:30 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/27 18:20:02 by rhlou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_cntr(char const *s, char c)
{
	size_t	i;
	size_t	nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			nw++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nw);
}

static void	ft_free_split(char **tab, size_t j)
{
	while (j > 0)
	{
		j--;
		free(tab[j]);
	}
	free(tab);
}

static char	**split2(char **res, char const *s, char c, size_t i)
{
	size_t	j;
	size_t	start;

	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = malloc(i - start + 1);
			if (!res[j])
			{
				ft_free_split(res, j);
				return (NULL);
			}
			ft_strlcpy(res[j++], s + start, i - start + 1);
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc((word_cntr(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (split2(res, s, c, i));
}
