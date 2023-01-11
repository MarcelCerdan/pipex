/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:59:26 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 17:07:25 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr(char *str, int n, int *index)
{
	if (n < 0)
	{
		str[*index] = '-';
		*index += 1;
		ft_putnbr(str, -n, index);
	}
	else if (n > 9)
	{
		ft_putnbr(str, n / 10, index);
		ft_putnbr(str, n % 10, index);
	}
	else
	{
		str[*index] = n % 10 + '0';
		*index += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;

	index = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((ft_count(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbr(str, n, &index);
	str[index] = '\0';
	return (str);
}
