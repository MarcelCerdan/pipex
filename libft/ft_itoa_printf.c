/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:59:26 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 11:32:15 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_printf(int n, unsigned int n_un, int size)
{
	int		count;

	count = 0;
	if (n == 0 && n_un == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0 || n_un != 0)
	{
		if (n > 0)
			n /= size;
		else
			n_un /= size;
		count++;
	}
	return (count);
}

void	ft_putnbr_printf(char *str, int n, size_t *index)
{
	if (n < 0)
	{
		str[*index] = '-';
		*index += 1;
		ft_putnbr_printf(str, -n, index);
	}
	else if (n > 9)
	{
		ft_putnbr_printf(str, n / 10, index);
		ft_putnbr_printf(str, n % 10, index);
	}
	else
	{
		str[*index] = n % 10 + '0';
		*index += 1;
	}
}

char	*ft_itoa_printf(int n)
{
	char			*str;
	size_t			index;

	index = 0;
	if (n == -2147483648)
		return ("-2147483648");
	str = malloc((ft_count_printf(n, 0, 10) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbr_printf(str, n, &index);
	str[index] = '\0';
	return (str);
}
