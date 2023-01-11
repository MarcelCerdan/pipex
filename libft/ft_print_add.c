/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:35:24 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 11:21:02 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnull(void)
{
	char	*null;
	int		count;

	count = 0;
	null = "(null)";
	while (*null)
	{
		count += ft_putchar(*null);
		null++;
	}
	return (count);
}

int	ft_count_add(size_t n, int size)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= size;
		count++;
	}
	return (count);
}

void	ft_putadd(char *str, size_t nbr, char *base, size_t *i)
{
	if (nbr >= 16)
	{
		ft_putadd(str, nbr / 16, base, i);
		ft_putadd(str, nbr % 16, base, i);
	}
	else
	{
		str[*i] = base[nbr];
		*i = *i + 1;
	}
}

char	*ft_print_add(void *add)
{
	char	*base;
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = (size_t) add;
	base = "0123456789abcdef";
	str = malloc((ft_count_add(n, 16) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putadd(str, n, base, &i);
	str[i] = '\0';
	return (str);
}
