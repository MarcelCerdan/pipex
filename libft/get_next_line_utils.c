/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:53:19 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/16 18:09:42 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dst;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = 0;
	size_dst = ft_strlen_gnl(dst);
	if ((dstsize > 0) && (dstsize >= size_dst))
	{
		while (src[i] && ((size_dst + i) < dstsize - 1))
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
		return (size_dst + ft_strlen_gnl(src));
	}
	return (dstsize + ft_strlen_gnl(src));
}

char	*ft_strjoin_gnl(char *s1, char const *s2, int s2_size)
{
	char	*joined_str;
	size_t	len;
	int		i;

	if (s2 == NULL)
		return (NULL);
	len = ft_strlen_gnl(s1) + s2_size;
	joined_str = malloc((len + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	joined_str[i] = 0;
	ft_strlcat_gnl(joined_str, s2, len + 1);
	return (joined_str);
}

int	ft_find_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_flush_buf(char *buf, char *line, int new_line)
{
	char	*joined_line;

	if (*buf == 0)
		return (line);
	if (new_line == -1)
		joined_line = ft_strjoin_gnl(line, buf, BUFFER_SIZE);
	else
		joined_line = ft_strjoin_gnl(line, buf, new_line + 1);
	free(line);
	ft_bufmove(buf, new_line, BUFFER_SIZE);
	return (joined_line);
}
