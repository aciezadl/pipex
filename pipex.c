/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:39:24 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 12:20:38 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_data data, char **envp, char **argv)
{
	pid_t	child1;
	pid_t	child2;
	int		pipefd[2];

	pipe(pipefd);
	child1 = fork();
	if (child1 == -1)
		return (perror("fork"), 1);
	if (child1 == 0)
		child_start(data, pipefd, envp, argv);
	child2 = fork();
	if (child2 == -1)
		return (perror("fork"), exit_status(child1));
	if (child2 == 0)
		child_end(data, pipefd, envp, argv);
	(close(pipefd[0]), close(pipefd[1]));
	return (exit_status(child2));
}

int	exit_status(pid_t child)
{
	int	exit;
	int	finish;
	int	status;

	while (1)
	{
		finish = wait(&status);
		if (finish == child)
		{
			if (WIFEXITED(status) != 0)
				exit = WEXITSTATUS(status);
		}
		if (finish <= 0)
			break ;
	}
	return (exit);
}
