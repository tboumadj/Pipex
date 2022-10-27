/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:07:37 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/27 14:43:50 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_bonus(t_pipexb *pb, char *argv, char **envp)
{
	pb->cmd = ft_split(argv, ' ');
	pb->cmd_path = get_path_bonus(pb, pb->cmd[0], envp);
	if (!pb->cmd_path)
	{
		free_process(pb->cmd);
		ft_close_err_bn("ERROR\n", pb);
	}
	if (execve(pb->cmd_path, pb->cmd, envp) == -1)
		ft_close_err_exec_bon(pb->cmd[0], pb);
}

void	create_proc(t_pipexb *pb, char *argv, char **envp)
{
	pid_t	pid;

	if (pipe(pb->fd) == -1)
		ft_close_err_bn("ERROR PIPE\n", pb);
	pid = fork();
	if (pid == -1)
		ft_close_err_bn("ERROR\n", pb);
	if (pid)
	{
		waitpid(0, NULL, 0);
		dup2(pb->fd[0], STDIN_FILENO);
		close(pb->fd[1]);
	}
	else if (pid == 0)
	{
		dup2(pb->fd[1], STDOUT_FILENO);
		close(pb->fd[0]);
		child_bonus(pb, argv, envp);
	}
}

void	road_hd(t_pipexb *pb, char *cmd, char **envp)
{
	pid_t	pid;

	if (pipe(pb->fd) == -1)
		ft_close_err_bn("ERROR PIPE\n", pb);
	pid = fork();
	if (pid == -1)
		ft_close_err_bn("ERROR\n", pb);
	if (pid)
	{
		waitpid(-1, NULL, 0);
		dup2(pb->fd[0], STDIN_FILENO);
		close(pb->fd[1]);
	}
	else if (pid == 0)
		here_doc(pb, cmd);
}

void	here_doc(t_pipexb *pb, char *cmd)
{
	size_t	i;
	char	*tmp;

	i = ft_strchr(cmd, 0);
	while (1)
	{
		write(1, "boumadj pipex - heredoc> ", 25);
		tmp = get_next_line(STDIN_FILENO);
		if (!tmp)
		{
			close(pb->fd[0]);
			close(pb->fd[1]);
			exit(EXIT_FAILURE);
		}
		if (tmp[i] == '\n' && cmd && ft_strncmp(tmp, cmd, i) == 0)
		{
			close(pb->fd[0]);
			close(pb->fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(tmp, pb->fd[1]);
		free(tmp);
		tmp = 0;
	}
	return ;
}

int	check_arg(char *argv1, t_pipexb *pb)
{
	if (argv1 && (ft_strncmp(argv1, "here_doc", 9) == 0))
	{
		pb->hd_count = 1;
		return (1);
	}
	else
	{
		pb->hd_count = 0;
		return (0);
	}
}
