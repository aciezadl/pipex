/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:42:54 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 15:40:29 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data, char **envp, char **argv)
{
	char	*path;

	data->line_path_envp = NULL;
	path = line_envp(envp);
	if (path != NULL)
	{
		data->line_path_envp = ft_split(path, ':');
		if (!data->line_path_envp)
			return ;
		free(path);
		ft_add_slash(data->line_path_envp);
		if (!data->line_path_envp)
			return ;
	}
	data->cmd1 = ft_check_cmd(argv[2], data);
	data->cmd2 = ft_check_cmd(argv[3], data);
	ft_free_tabtab(data->line_path_envp);
	if (data->cmd1 == NULL)
		data->write_cmd1 = NULL;
	else
		data->write_cmd1 = ft_split(argv[2], ' ');
	if (data->cmd2 == NULL)
		data->write_cmd2 = NULL;
	else
		data->write_cmd2 = ft_split(argv[3], ' ');
}

char	*line_envp(char **envp)
{
	char	*line;

	line = NULL;
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			line = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
			return (line);
		}
		envp++;
	}
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_check_cmd(char *cmd, t_data *data)
{
	char	*path_cmd;
	int		i;

	i = 0;
	path_cmd = NULL;
	if (cmd[0] == 0)
		return (write(2, "permission denied\n", 18), NULL);
	if (check_slash(cmd) == 1)
	{
		path_cmd = ft_remove_arg(cmd);
		if (access(path_cmd, F_OK | X_OK) == -1)
		{
			perror(path_cmd);
			return (free(path_cmd), NULL);
		}
		return (path_cmd);
	}
	path_cmd = path_finder(cmd, *data);
	if (!path_cmd)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": command not found\n", 20);
		return (NULL);
	}
	return (path_cmd);
}

char	*path_finder(char *cmd, t_data data)
{
	char	*res;
	char	**res_split_cmd;
	int		i;

	i = 0;
	res_split_cmd = ft_split(cmd, ' ');
	if (!res_split_cmd || data.line_path_envp == NULL)
		return (ft_free_tabtab(data.line_path_envp),
			ft_free_tabtab(res_split_cmd), NULL);
	while (data.line_path_envp[i] != NULL)
	{
		res = ft_strjoin(data.line_path_envp[i], res_split_cmd[0]);
		if (!res)
			return (ft_free_tabtab(res_split_cmd), NULL);
		if (access(res, F_OK | X_OK) == 0)
			break ;
		else
		{
			free(res);
			res = NULL;
			i++;
		}
	}
	ft_free_tabtab(res_split_cmd);
	return (res);
}

char	*ft_remove_arg(char *str)
{
	char	**res_split;
	char	*res;
	int		i;

	i = 0;
	res_split = ft_split(str, ' ');
	res = ft_strdup(res_split[0]);
	ft_free_tabtab(res_split);
	return (res);
}
