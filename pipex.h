/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:13:39 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/16 23:00:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_find_path(char *argv, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	display_error(int nb, char *error);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *left_str, char *buf);
void	ft_execute(char *argv, char **env);

#endif