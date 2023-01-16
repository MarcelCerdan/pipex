/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:36:54 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/24 18:18:11 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bufmove(char *buf, int new_line, int size)
{
	int	i;

	i = 0;
	while (i + new_line + 1 < size && new_line != -1)
	{
		buf[i] = buf[i + new_line + 1];
		i++;
	}
	while (i < size)
		buf[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	int			ret_read;
	char		*full_line;
	int			new_line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	ret_read = 1;
	full_line = NULL;
	new_line = ft_find_new_line(buf);
	while (ret_read > 0 && new_line == -1)
	{
		if (*buf != 0)
			full_line = ft_flush_buf(buf, full_line, new_line);
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read == -1)
			return (NULL);
		new_line = ft_find_new_line(buf);
	}
	return (ft_flush_buf(buf, full_line, new_line));
}
