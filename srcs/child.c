/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:48 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/11 18:42:39 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	child(int f, char *cmd, int tube[2], char **envp)
{
	char	**path;
	char	**cmd_args;
	char	*mycmd;
	int		i;

	i = -1;
	if (dup2(f, 0) < 0)
		error("Child dup2 input");
	if (dup2(tube[1], 1) < 0)
		error("Child dup2 output");
	path = cmd_path(envp);
	cmd_args = ft_split(cmd, ' ');
	close(tube[0]);
	close(f);
	while (path[++i])
	{
		mycmd = ft_strjoin(path[i], cmd_args[0]);
		if (!mycmd)
			return (err_msg("Error during ft_join in child.\n"));
		execve(mycmd, cmd_args, envp);
		free(mycmd);
	}
	return (EXIT_FAILURE);
}

int	parent(int f, char *cmd, int tube[2], char **envp)
{
	int		status;
	int		i;
	char	**cmd_args;
	char	**path;
	char	*mycmd;

	i = -1;
	waitpid(-1, &status, 0);
	if (dup2(f, 1) < 0)
		error("Parent dup2 output");
	if (dup2(tube[0], 0))
		error("Parent dup2 input");
	path = cmd_path(envp);
	cmd_args = ft_split(cmd, ' ');
	close(tube[1]);
	close(f);
	while (path[++i])
	{
		mycmd = ft_strjoin(path[i], cmd_args[0]);
		if (!mycmd)
			return (err_msg("Error during ft_join in parent.\n"));
		execve(mycmd, cmd_args, envp);
		free(mycmd);
	}
	return (EXIT_FAILURE);
}
