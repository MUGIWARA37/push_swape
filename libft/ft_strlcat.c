/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:01:48 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 15:04:13 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	if (!dst && !dstsize)
		return (0);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0)
		return (dstsize + len_src);
	i = 0;
	while (dst[i] && i < dstsize)
		++i;
	j = 0;
	while (src[j] && (i < dstsize - 1))
		dst[i++] = src[j++];
	if (i < dstsize)
		dst[i] = '\0';
	if (dstsize < len_dst)
		return (len_src + dstsize);
	return (len_src + len_dst);
}
