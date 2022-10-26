/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:15:56 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/26 16:25:45 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_err(char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_close_err_exec(char *str, t_pipex *pipex)
{
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putstr_fd(str, 2);
	ft_close_fd(pipex);
	exit(EXIT_FAILURE);
}

void	free_process(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free (tmp);
}

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}
