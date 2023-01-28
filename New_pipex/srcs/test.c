/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:56:55 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/27 20:16:54 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(void)
{
	int fd_in = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	while (1)
	{
		ft_dprintf(1, "> ");
		char *line = get_next_line(0);
		ft_dprintf(1, "line : %s", line);
		ft_dprintf(fd_in, "line : %s", line);
	}
}