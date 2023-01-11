/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:39:02 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 16:28:40 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

void	pipex(int f1, int f2, char **av, char **envp);
void	error(char *err);
int		err_msg(char *err);
int		child(int f, char *cmd, int tube[2]);
int		parent(int f, char *cmd, int tube[2]);

#endif
