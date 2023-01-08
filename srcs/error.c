/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:46 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/08 18:15:42 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int err_msg(char *err)
{
    write(2, err, ft_strlen(err));
    return(1);
}

void    error(char *err)
{
    perror(err);
    exit(1);
}