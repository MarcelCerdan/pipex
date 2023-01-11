/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:36:01 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 11:22:13 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_param(char c, va_list params)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(params, int));
	else if (c == 's')
		count = ft_putstr(va_arg(params, char *), c);
	else if (c == 'p')
		count = ft_putstr(ft_print_add(va_arg(params, void *)), c);
	else if (c == 'd' || c == 'i')
		count = ft_putstr(ft_itoa_printf(va_arg(params, int)), c);
	else if (c == 'u')
		count = ft_putstr(ft_putunsigned(va_arg(params, int)), c);
	else if (c == 'x' || c == 'X')
		count = ft_putstr(ft_puthexa(va_arg(params, int), c), c);
	else if (c == '%')
		count = ft_putchar('%');
	else if (c != '\0')
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	int		res;
	va_list	params;

	i = 0;
	res = 0;
	count = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			res = ft_find_param(str[i++], params);
			if (res < 0)
				return (-1);
			count += res;
		}
		else if (str[i] != '%')
			count += ft_putchar(str[i++]);
		else
			i++;
	}
	return (count);
}
