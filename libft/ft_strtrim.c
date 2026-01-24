/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:00:40 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 15:04:13 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		--end;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
