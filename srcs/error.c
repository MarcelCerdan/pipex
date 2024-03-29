/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:46 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/11 15:03:36 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	err_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	error(char *err)
{
	perror(err);
	exit(1);
}
