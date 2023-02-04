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

static char	**ft_freesplit(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(dst[i]);
		i--;
	}
	return (free(dst), NULL);
}

char	*find_cmd(char **envp, char *cmd_arg)
{
	int		i;
	char	*cmd;
	char	**cmd_path;

	cmd_path = find_path(envp);
	i = -1;
	while (cmd_path[++i])
	{
		cmd = ft_strjoin(cmd_path[i], cmd_arg);
		if (!cmd)
		{
			ft_freesplit(cmd_path);
			error("find_cmd malloc");
		}
		if (access(cmd, 0) == 0)
			return (free(cmd_path), cmd);
		free(cmd);
	}
	free(cmd_path);
	err_msg(cmd_arg);
	free(cmd_arg);
	err_msg(" : command not found\n");
	return (NULL);
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
	if (mycmd == NULL)
	{
		free(cmd_args);
		exit(1);
	}
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
	if (mycmd == NULL)
	{
		free(cmd_args);
		exit(1);
	}
	execve(mycmd, cmd_args, envp);
	return (EXIT_FAILURE);
}
