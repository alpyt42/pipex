/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:06:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/28 18:43:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	check_files(t_data *pipex)
{
	if (!ft_strncmp("here_doc", pipex->av[1], 9))
	{
		get_here_doc(pipex);
		pipex->out = open(pipex->av[pipex->ac - 1],\
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->out == -1)
			return (perror("open"), 0);
		pipex->h_doc = 1;
	}
	else
	{
		pipex->in = open(pipex->av[1], O_RDONLY);
		if (pipex->in == -1)
			return (perror("open"), 0);
		pipex->out = open(pipex->av[pipex->ac - 1],\
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->out == -1)
			return (perror("open"), 0);
	}
	pipex->n_cmds = pipex->ac - 3 - pipex->h_doc;
}

int	main(int ac, char **av, char **en)
{
	t_data	pipex;

	pipex.en = en;
	pipex.ac = ac;
	pipex.av = av;
	pipex.h_doc = 0;
	if (ac >= 5)
	{
		if (!check_files(&pipex))
			return (1);
		
	}
	else
		ft_dprintf(2, "error: invalid number of arguments");
	return (0);
}