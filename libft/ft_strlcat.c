/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:00:44 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 17:29:26 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dst;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = 0;
	size_dst = ft_strlen(dst);
	if ((dstsize > 0) && (dstsize >= size_dst))
	{
		while (src[i] && ((size_dst + i) < dstsize - 1))
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
		return (size_dst + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
