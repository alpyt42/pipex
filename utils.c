/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:08:23 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/16 11:44:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	display_error(int nb, char *error)
{
	if (nb == 0)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	}
	else if (nb == 1)
		ft_putstr_fd("\033[31mError\n\e[0m", 2);
	else if (nb == 2)
	{
		
	}
	return (0);
}

char **ft_find_path(char **env)
{
	int		i;
	char	**roots;
	char	*path;

	i = 0;
	roots = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_strjoin("", &env[i][5]);
			roots = ft_split(path, ':');
			free(path);
			return (roots);
		}
		i++;
	}
	return (NULL);
}

void ft_execute(char **argv, char **env)
{
	
}