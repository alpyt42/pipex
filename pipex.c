/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:59:16 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/16 16:17:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	child_proc(char **argv, char **env, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		return (display_error(0, ""));
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (display_error(0, ""));
	if (dup2(file1, STDIN_FILENO) == -1)
		return (display_error(0, ""));
	close (fd[1]);
	ft_execute(argv, env);
	return (0);
}

static int	parent_proc(char **argv, char **env, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_RDONLY);
	if (file2 == -1)
		return (display_error(0, ""));
	if (dup2(fd[0], STDOUT_FILENO) == -1)
		return (display_error(0, ""));
	if (dup2(file2, STDIN_FILENO) == -1)
		return (display_error(0, ""));
	close (fd[0]);
	ft_execute(argv, env);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid_fork;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (display_error(1, ""));
		pid_fork = fork();
		if (pid_fork == -1)
			return (display_error(1, ""));
		if (pid_fork == 0)
			child_proc(argv, env, fd);
		waitpid(pid_fork, NULL, 0);
		parent_proc(argv, env, fd);
	}
	else
		return (display_error(0, ""));
	return (0);
}
