/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:45:30 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/24 18:59:47 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

static char	*ft_join(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = malloc((len + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	joined_str[i] = 0;
	ft_strlcat(joined_str, s2, len + 1);
	return (joined_str);
}

char	**ft_freesplit(char **dst)
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
	free(path);
	if (!split_path)
		error("cmd_path malloc");
	i = 0;
	while (split_path[i])
	{
		split_path[i] = ft_strjoin(split_path[i], "/");
		if (!split_path[i])
			exit(err_msg("Error in path\n"));
		i++;
	}
	return (split_path);
}

char	*find_cmd(char **cmd_path, char *cmd_arg)
{
	int		i;
	char	*cmd;

	i = -1;
	while (cmd_path[++i])
	{
		cmd = ft_join(cmd_path[i], cmd_arg);
		if (!cmd)
			exit(err_msg("Error in command\n"));
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
	}
	err_msg(cmd_arg);
	err_msg(" : command not found\n");
	return (NULL);
}
