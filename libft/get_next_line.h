/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:08 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/16 17:47:37 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize);
int		ft_find_new_line(char *buf);
void	ft_bufmove(char *buf, int new_line, int size);
char	*ft_flush_buf(char *buf, char *line, int new_line);
char	*ft_strjoin_gnl(char *s1, char const *s2, int s2_size);
char	*get_next_line(int fd);

#endif
