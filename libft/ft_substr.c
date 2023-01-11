/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:03:59 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/25 17:01:10 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	size;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else
		size = ft_strlen(start + s);
	if (size > len)
		size = len;
	cpy = malloc((size + 1) * sizeof(char));
	if (cpy == NULL)
		return (free(cpy), NULL);
	ft_strlcpy(cpy, s + start, size + 1);
	return (cpy);
}
