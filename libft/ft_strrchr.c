/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:01:56 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 19:15:23 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*cpy_s;
	char	*last_occ;
	int		flag;

	cpy_s = (char *) s;
	flag = 0;
	while (*cpy_s)
	{
		if (*cpy_s == (char) c)
		{
			last_occ = cpy_s;
			flag = 1;
		}
		cpy_s++;
	}
	if ((flag == 0) && (*cpy_s == (char) c))
		return (cpy_s);
	else if (flag == 0)
		return (0);
	else
		return (last_occ);
}
