/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:32:41 by aciezadl          #+#    #+#             */
/*   Updated: 2024/03/04 15:42:12 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		return (1);
	init_data(&data, envp, argv);
	pipex(data, envp, argv);
	ft_free_tabtab(data.write_cmd1);
	ft_free_tabtab(data.write_cmd2);
	free(data.cmd1);
	free(data.cmd2);
	return (0);
}
