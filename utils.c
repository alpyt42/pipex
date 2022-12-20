/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:08:23 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/20 09:21:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	display_error(int nb, char *error)
{
	if (nb == -1)
		ft_putstr_fd("\033[31mPermission denied\n\e[0m", 2);
	if (nb == 0)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	}
	else if (nb == 1)
		ft_putstr_fd("\033[31mError\n\e[0m", 2);
	else if (nb == 2)
	{
		ft_putstr_fd(ft_strjoin("\033[31mThis command doesn't exist : \e[0m", error), 2);
		ft_putstr_fd("\n", 2);
	}
	else if (nb == 3)
	{
		ft_putstr_fd(ft_strjoin("\033[31mError when executing the command : \e[0m", error), 2);
		ft_putstr_fd("\n", 2);
	}
	if (nb != 2 && nb != 3)
		exit(EXIT_FAILURE);
}

char *ft_find_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*test_path;
	char	**all_paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	all_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		test_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(test_path, cmd);
		free(test_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
	return (NULL);
}

void ft_execute(char *argv, char **env)
{
	int 	i;
	char	**cmd;
	char	*path;

	i = -1;
	if (access(argv, F_OK) == 0)
	{
		path = ft_strjoin("", argv);
		cmd = ft_split(argv, ' ');
	}
	else
	{
		cmd = ft_split(argv, ' ');
		path = ft_find_path(cmd[0], env);
	}
	if (!path)
	{
		display_error(2, cmd[0]);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else if (execve(path, cmd, env) == -1)
		display_error(3, cmd[0]);
}