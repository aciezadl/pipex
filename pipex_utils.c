/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:46:40 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 15:42:54 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(t_data data)
{
	ft_free_tabtab(data.write_cmd1);
	ft_free_tabtab(data.write_cmd2);
	free(data.cmd1);
	free(data.cmd2);
}

void	ft_free_tabtab(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_add_slash(char **str)
{
	char	*tmp;

	while (*str)
	{
		tmp = ft_strjoin(*str, "/");
		free(*str);
		*str = tmp;
		str++;
	}
}

char	**write_cmd(char *str)
{
	char	**cmd;

	cmd = ft_split(str, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}

int	check_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

// void	ft_print_tabtab(char **str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 	{
// 		fprintf(stderr, "write_cmd vaut NULL\n");
// 		return ;
// 	}
// 	while (str[i] != 0)
// 	{
// 		fprintf(stderr, "write_cmd1 apres init %d : %s\n", i, str[i]);
// 		i++;
// 	}
// }
