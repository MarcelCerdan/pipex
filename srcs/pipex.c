/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:34:17 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 16:26:34 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **av, char **envp)
{
	int		tube[2];
	pid_t	parent;

	if (pipe(tube) < 0)
		return (error("Pipe"));
	parent = fork();
	if (parent < 0)
		return (error("Fork"));
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
