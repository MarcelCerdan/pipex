/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:34:17 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/13 14:24:04 by mthibaul         ###   ########lyon.fr   */
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
	int		i;
	pid_t	*pid;

	i = 1;
	while (i < av[i + 1])
		pid[i - 1] = fork();
	if (pid < 0)
		return (error("Fork"));
	if (pipe(tube) < 0)
		return (error("Pipe"));
	if (i != 1)
		f1 = tube[0];
	if (pid == 0)
		child(f1, av[i], tube, envp);
	else if (av[i + 2])
		parent(tube[1], av[i + 1], tube, envp);
	else
		parent(f2, av[i + 1], tube, envp);
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	if (ac < 5)
		return (err_msg("Error: invalid number of arguments.\n"));
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		error(av[1]);
	if (f2 < 0)
		error(av[ac - 1]);
	pipex(f1, f2, av, envp);
}
