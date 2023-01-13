/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:48 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/13 16:17:20 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

char	*find_cmd(char **envp, char **cmd_args)
{
	int		i;
	char	*cmd;
	char	**path;

	i = 0;
	path = cmd_path(envp);
	while (path[i++])
	{
		cmd = ft_strjoin(path[i], cmd_args[0]);
		if (access(cmd, F_OK | R_OK | X_OK) == 0)
		{
			free(path);
			return (cmd);
		}
		free(cmd);
	}
	free(path);
	err_msg(cmd_args[0]);
	err_msg(" : command not found\n");
	exit(1);
}

int	child(int f, char *cmd, int tube[2], char **envp)
{
	char	**cmd_args;
	char	*mycmd;
	int		i;

	i = -1;
	if (dup2(f, 0) < 0 || dup2(tube[1], 1) < 0)
		error("Child dup2");
	cmd_args = ft_split(cmd, ' ');
	close(tube[0]);
	close(f);
	mycmd = find_cmd(envp, cmd_args);
	execve(mycmd, cmd_args, envp);
	return (EXIT_FAILURE);
}

int	parent(int f, char *cmd, int tube[2], char **envp)
{
	int		status;
	char	**cmd_args;
	char	*mycmd;

	waitpid(-1, &status, 0);
	if (dup2(f, 1) < 0 || dup2(tube[0], 0) < 0)
		error("Parent dup2");
	cmd_args = ft_split(cmd, ' ');
	close(tube[1]);
	close(f);
	mycmd = find_cmd(envp, cmd_args);
	execve(mycmd, cmd_args, envp);
	return (EXIT_FAILURE);
}
