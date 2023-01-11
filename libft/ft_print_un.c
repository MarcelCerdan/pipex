/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:15:33 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 11:45:26 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_un(char *str, unsigned int n_un, size_t *index)
{
	if (n_un > 9)
	{
		ft_putnbr_un(str, n_un / 10, index);
		ft_putnbr_un(str, n_un % 10, index);
	}
	else
	{
		str[*index] = n_un % 10 + '0';
		*index += 1;
	}
}

char	*ft_putunsigned(int n)
{
	unsigned int	n_unsigned;
	char			*str;
	size_t			index;

	if (n < 0)
		n_unsigned = n + UINT_MAX + 1;
	else
		n_unsigned = n;
	index = 0;
	str = malloc((ft_count_printf(0, n_unsigned, 10) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbr_un(str, n_unsigned, &index);
	str[index] = '\0';
	return (str);
}
