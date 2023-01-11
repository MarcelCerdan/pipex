/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:57:45 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:20 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	size;
	int	i;
	int	last_i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		last_i = i;
		while (s[i] != c && s[i])
			i++;
		if (last_i != i)
			size++;
	}
	return (size);
}

static char	**ft_freesplit(char **dst, int i)
{
	while (i >= 0)
	{
		free(dst[i]);
		i--;
	}
	return (NULL);
}

static char	**ft_split_strs(char **dst, char const *src, char c)
{
	int	nb_wrd;
	int	i;
	int	last_i;

	nb_wrd = 0;
	last_i = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] == c)
			i++;
		last_i = i;
		while (src[i] != c && src[i])
			i++;
		if (last_i != i)
		{
			dst[nb_wrd] = ft_substr(src, last_i, i - last_i);
			if (dst[nb_wrd] == NULL)
				return (ft_freesplit(dst, nb_wrd));
			nb_wrd++;
		}
	}
	dst[nb_wrd] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	if (ft_split_strs(str, s, c) == NULL)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
