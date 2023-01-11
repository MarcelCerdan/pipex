/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:49:48 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 19:14:13 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*cpy_s;

	cpy_s = (char *) s;
	while (*cpy_s)
	{
		if (*cpy_s == (char) c)
			return (cpy_s);
		cpy_s++;
	}
	if (*cpy_s != (char) c)
		return (0);
	else
		return (cpy_s);
}
