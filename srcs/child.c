/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:48 by mthibaul          #+#    #+#             */
/*   Updated: 2023/02/03 14:33:07 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	*find_cmd(char **envp, char *cmd_arg)
{
	char	*cmd;
	char	**cmd_path;

	cmd_path = find_path(envp);
	while (*cmd_path)
	{
		cmd = ft_strjoin(*cmd_path, cmd_arg);
		if (!cmd)
			error("find_cmd malloc");
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		cmd_path++;
	}
	err_msg(cmd_arg);
	err_msg(" : command not found\n");
	exit(1);
}

int	child(int f, char *cmd, int tube[2], char **envp)
{
	char	**cmd_args;
	char	*mycmd;

	if (dup2(f, 0) < 0 || dup2(tube[1], 1) < 0)
		error("Child dup2");
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error("Parent malloc");
	close(tube[0]);
	close(f);
	mycmd = find_cmd(envp, cmd_args[0]);
	execve(mycmd, cmd_args, envp);
	return (EXIT_FAILURE);
}

int	parent(int f, char *cmd, int tube[2], char **envp)
{
	char	**cmd_args;
	char	*mycmd;

	if (dup2(f, 1) < 0 || dup2(tube[0], 0) < 0)
		error("Parent dup2");
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error("Parent malloc");
	close(tube[1]);
	close(f);
	mycmd = find_cmd(envp, cmd_args[0]);
	execve(mycmd, cmd_args, envp);
	return (EXIT_FAILURE);
}
