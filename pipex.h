/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:42:40 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 15:23:09 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**line_path_envp;
	char	*cmd1;
	char	*cmd2;
	char	**write_cmd1;
	char	**write_cmd2;
	int		infile;
	int		outfile;
}			t_data;

int			pipex(t_data data, char **envp, char **argv);
int			exit_status(pid_t child);
void		init_data(t_data *data, char **envp, char **argv);
char		*line_envp(char **envp);
char		*ft_check_cmd(char *cmd, t_data *data);
char		*path_finder(char *cmd, t_data data);
void		ft_add_slash(char **str);
char		*ft_remove_arg(char *str);
int			check_slash(char *str);
char		**write_cmd(char *str);
void		ft_print_tabtab(char **str);
void		ft_free_tabtab(char **str);
void		ft_free_all(t_data data);
void		child_start(t_data data, int *pipefd, char **envp, char **argv);
void		child_end(t_data data, int *pipefd, char **envp, char **argv);

#endif