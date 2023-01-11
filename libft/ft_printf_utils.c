/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:45:01 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 15:01:24 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, char c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	if (str == NULL && c == 's')
		return (ft_printnull());
	else if (str == NULL)
		return (-1);
	else if (c == 'p')
	{
		count += ft_putchar('0');
		count += ft_putchar('x');
	}
	while (str && str[i])
	{
		if (ft_putchar(str[i]) < 0)
			return (-1);
		count++;
		i++;
	}
	if (c != 's' && ft_strncmp(str, "-2147483648", 11))
		free(str);
	return (count);
}

void	ft_putnbrhexa(char *str, unsigned int nbr, char *base, int *i)
{
	if (nbr >= 16)
	{
		ft_putnbrhexa(str, nbr / 16, base, i);
		ft_putnbrhexa(str, nbr % 16, base, i);
	}
	else
	{
		str[*i] = base[nbr];
		*i = *i + 1;
	}
}

char	*ft_puthexa(int n, char c)
{
	char			*base;
	char			*str;
	int				i;
	unsigned int	n_un;

	i = 0;
	if (n < 0)
		n_un = n + UINT_MAX + 1;
	else
		n_un = n;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	str = malloc((ft_count_printf(0, n_un, 16) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbrhexa(str, n_un, base, &i);
	str[i] = '\0';
	return (str);
}
