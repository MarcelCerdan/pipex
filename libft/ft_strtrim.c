/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:34 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/11 17:53:35 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i++;
		else
			return (i);
	}
	return (0);
}

static size_t	ft_find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[ft_strlen(s1) - 1 - i] && i < ft_strlen(s1) - 1)
	{
		j = 0;
		while (s1[ft_strlen(s1) - 1 - i] != set[j] && set[j])
			j++;
		if (s1[ft_strlen(s1) - 1 - i] == set[j])
			i++;
		else
			return (ft_strlen(s1) - i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	str = malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
