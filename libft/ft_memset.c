/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:05:10 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/07 16:55:08 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*cpy;

	cpy = (unsigned char *) s;
	i = 0;
	while (i < len)
		cpy[i++] = (unsigned char) c;
	s = cpy;
	return (s);
}
