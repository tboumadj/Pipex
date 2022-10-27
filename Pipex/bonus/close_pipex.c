/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:33:17 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/27 11:16:09 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close_err_nor(char *str, t_pipex *pipex)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(str, 2);
	ft_close_fd(pipex);
	exit(EXIT_FAILURE);
}

void	ft_close_err_exec(char *str, t_pipex *pipex)
{
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putendl_fd(str, 2);
	ft_close_fd(pipex);
	exit(EXIT_FAILURE);
}

void	ft_close_err_exec_bon(char *str, t_pipexb *pb)
{
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putendl_fd(str, 2);
	ft_close_fd_bon(pb);
	exit(EXIT_FAILURE);
}

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	ft_close_fd_bon(t_pipexb *pb)
{
	close(pb->fd[0]);
	close(pb->fd[1]);
}
