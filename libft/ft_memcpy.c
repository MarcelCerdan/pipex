/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:56:45 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 17:14:53 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	if (dst == NULL && src == NULL && n)
		return (NULL);
	cpy_src = (unsigned char *) src;
	cpy_dst = (unsigned char *) dst;
	i = 0;
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		i++;
	}
	dst = cpy_dst;
	return (dst);
}
