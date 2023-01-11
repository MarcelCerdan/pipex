/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:36:15 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 18:40:01 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*cpy_dst;

	cpy_dst = (unsigned char *) dst;
	if (!dst && !src && n)
		return (NULL);
	if ((src + n >= dst) && (src < dst))
	{
		i = n - 1;
		while (i >= 0)
		{
			cpy_dst[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t) i < n)
		{
			cpy_dst[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
