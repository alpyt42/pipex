/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:06:51 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/28 17:37:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		ac;
	char	**av;
	pid_t	*p_id;
	char	***cmds;
	char	**en;
	int		n_cmds;
	int		**fds;
	int		in;
	int		out;
	int		h_doc;
}	t_data;

void	get_here_doc(t_data *pipex);

#endif