/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:45:30 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/16 14:16:08 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

char	**cmd_path(char **envp)
{
	int		i;
	char	*path;
	char	**split_path;

	i = 0;
	path = NULL;
	while (envp[i] && !path)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 4);
		i++;
	}
	split_path = ft_split(path, ':');
	if (!split_path)
	{
		free(split_path);
		error("Split commande path");
	}
	i = 0;
	while (split_path[i])
	{
		split_path[i] = ft_strjoin(split_path[i], "/");
		i++;
	}
	return (split_path);
}

char	*find_cmd(char **cmd_path, char *cmd_arg)
{
	char	*cmd;

	while (*cmd_path)
	{
		cmd = ft_strjoin(*cmd_path, cmd_arg);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		cmd_path++;
	}
	err_msg(cmd_arg);
	err_msg(" : command not found\n");
	exit(1);
}
