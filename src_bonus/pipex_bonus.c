/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:34:17 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/17 16:18:22 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

void	get_infile(char **av, t_pipex *pipex)
{
	if (!pipex->here_doc)
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile < 0)
			error(av[1]);
	}
	else
		here_doc(av[2], pipex);
}

void	get_outfile(char *file, t_pipex *pipex)
{
	if (!pipex->here_doc)
		pipex->outfile = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		pipex->outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->outfile < 0)
		error(file);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nb)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	do_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nb)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			return (error("Pipe"));
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_pipex	pipex;

	if (ac < check_arg(av[1], &pipex))
		return (err_msg("Error: invalid number of arguments.\n"));
	get_infile(av, &pipex);
	get_outfile(av[ac - 1], &pipex);
	pipex.cmd_nb = ac - 3 - pipex.here_doc;
	pipex.pipe_nb = 2 * (pipex.cmd_nb - 1);
	pipex.pipe = malloc(sizeof(int) * pipex.pipe_nb);
	if (!pipex.pipe)
		error("Pipe malloc");
	pipex.cmd_path = cmd_path(envp);
	do_pipes(&pipex);
	pipex.index = -1;
	while (++(pipex.index) < pipex.cmd_nb)
		child(pipex, av, envp);
	close_pipes(&pipex);
	unlink(".here_doc");
	waitpid(-1, &status, 0);
	return (0);
}
