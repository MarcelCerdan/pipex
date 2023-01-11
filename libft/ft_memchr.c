/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:35:47 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/08 18:07:17 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_s;

	cpy_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (cpy_s[i] == (unsigned char) c)
			return (&(cpy_s[i]));
		i++;
	}
	return (0);
}
