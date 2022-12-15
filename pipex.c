/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:59:16 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 21:04:58 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_proc()
{
	
}

static void	child_proc()
{
	
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (display_error(1, ""));
	}
	else
		return (display_error(0, ""));
	return (0);
}
