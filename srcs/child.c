/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:48 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/08 19:25:01 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int child(int f, char *cmd, int **tube)
{
    if(dup2(f, 0) < 0)
        error("Child dup2 input");
    if(dup2(tube[1], 1) < 0)
        error("Child dup2 output");
    close(tube[0]);
    close(f);
}

int parent(int f, char *cmd, int **tube)
{
    int status;

    waitpid(-1, &status, 0);
    if (dup2(f, 1) < 0)
        error("Parent dup2 output");
    if (dup2(tube[0], 0))
        error("Parent dup2 input");
    close(tube[1]);
    close(f);
}