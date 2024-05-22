/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:40:57 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 15:25:46 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_start(t_data data, int *pipefd, char **envp, char **argv)
{
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		perror(argv[1]);
		ft_free_all(data);
		(close(pipefd[0]), close(pipefd[1]));
		exit(EXIT_FAILURE);
	}
	data.infile = open(argv[1], O_RDONLY);
	ft_free_tabtab(data.write_cmd2);
	free(data.cmd2);
	close(pipefd[0]);
	dup2(data.infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	(close(pipefd[1]), close(data.infile));
	if (data.cmd1 != NULL)
		execve(data.cmd1, data.write_cmd1, envp);
	ft_free_tabtab(data.write_cmd1);
	free(data.cmd1);
	exit(EXIT_FAILURE);
}

void	child_end(t_data data, int *pipefd, char **envp, char **argv)
{
	data.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_free_tabtab(data.write_cmd1);
	free(data.cmd1);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	(close(pipefd[0]), close(data.outfile));
	if (data.cmd2 != NULL)
		execve(data.cmd2, data.write_cmd2, envp);
	ft_free_tabtab(data.write_cmd2);
	free(data.cmd2);
	exit(EXIT_FAILURE);
}
