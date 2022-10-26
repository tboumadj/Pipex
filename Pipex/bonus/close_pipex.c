/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:33:17 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/26 15:15:49 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close_err(char *str)
{
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_process(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}
