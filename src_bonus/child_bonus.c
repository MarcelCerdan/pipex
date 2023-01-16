/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:48 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/16 15:21:03 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

static void	do_dup(int in, int out)
{
	if (dup2(in, 0) < 0 || dup2(out, 1) < 0)
		error("Dup2");
}

void	child(t_pipex p, char **av, char **envp)
{
	p.pid = fork();
	if (p.pid < 0)
		error("Fork");
	else if (!p.pid)
	{
		if (p.index == 0)
			do_dup(p.infile, p.pipe[1]);
		else if (p.index == p.cmd_nb - 1)
			do_dup(p.pipe[2 * p.index - 2], p.outfile);
		else
			do_dup(p.pipe[2 * p.index - 2], p.pipe[2 * p.index + 1]);
		close_pipes(&p);
		p.cmd_args = ft_split(av[2 + p.index], ' ');
		p.cmd = find_cmd(p.cmd_path, p.cmd_args[0]);
		execve(p.cmd, p.cmd_args, envp);
	}
}
