/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:34:17 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/24 18:21:08 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	**find_path(char **envp)
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
		i++;
	}
	return (split_path);
}

void	pipex(int f1, int f2, char **av, char **envp)
{
	int		tube[2];
	pid_t	pid;

	if (pipe(tube) < 0)
		return (error("Pipe"));
	pid = fork();
	if (pid < 0)
		return (error("Fork"));
	if (pid == 0)
		child(f1, av[2], tube, envp);
	else
		parent(f2, av[3], tube, envp);
	waitpid(-1, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	if (ac != 5)
		return (err_msg("Error: invalid number of arguments.\n"));
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		error(av[1]);
	if (f2 < 0)
		error(av[4]);
	pipex(f1, f2, av, envp);
}
