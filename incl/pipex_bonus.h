/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:39:02 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/16 14:04:23 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_nb;
	int		pipe_nb;
	int		index;
	int		*pipe;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_path;
	pid_t	pid;
}	t_pipex;

void	do_pipe(t_pipex *pipex);
void	error(char *err);
void	close_pipes(t_pipex *pipex);
void	child(t_pipex pipex, char **av, char **envp);
int		err_msg(char *err);
char	*find_cmd(char **envp, char *cmd_args);
char	**cmd_path(char **envp);

#endif
