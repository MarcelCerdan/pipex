/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:09:49 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/24 18:56:13 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "get_next_line.h"

int	check_arg(char *arg, t_pipex *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *av, t_pipex *pipex)
{
	int		fd;
	char	*line;

	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		error("Here_doc");
	while (ft_strncmp(av, line, ft_strlen(line) - 1) != 0 || line[0] == 10)
	{
		write(1, "pipex heredoc> ", 16);
		line = get_next_line(0);
		if (!line)
			error("Get_next_line");
		if (ft_strncmp(av, line, ft_strlen(line) - 1) != 0 || line[0] == 10)
		{
			write(fd, line, ft_strlen(line));
			free(line);
		}
	}
	free(line);
	close(fd);
	pipex->infile = open(".here_doc", O_RDONLY);
	if (pipex->infile < 0)
		error(".here_doc");
}
