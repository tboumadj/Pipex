/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:49:33 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/27 14:23:11 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd = ft_split(argv[2], ' ');
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->filein, STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->cmd_path = get_path(pipex, pipex->cmd[0], envp);
	if (!pipex->cmd_path)
	{
		free_process(pipex->cmd);
		ft_close_err_nor("ERROR\n", pipex);
	}
	if (execve(pipex->cmd_path, pipex->cmd, envp) == -1)
		ft_close_err_exec(pipex->cmd[0], pipex);
}

void	ft_parent(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd = ft_split(argv[3], ' ');
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->fileout, STDOUT_FILENO);
	close(pipex->fd[1]);
	pipex->cmd_path = get_path(pipex, pipex->cmd[0], envp);
	if (!pipex->cmd_path)
	{
		free_process(pipex->cmd);
		ft_close_err_nor("ERROR\n", pipex);
	}
	if (execve(pipex->cmd_path, pipex->cmd, envp) == -1)
		ft_close_err_exec(pipex->cmd[0], pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_close_err("ERROR ARGUMENT\n");
	pipex.filein = open(argv[1], O_RDONLY);
	if (pipex.filein == -1)
		ft_close_err("ERROR WITH INFILE\n");
	pipex.fileout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fileout == -1)
		ft_close_err("ERROR WITH OUTFILE\n");
	if (pipe(pipex.fd) == -1)
		ft_close_err_nor("ERROR PIPE\n", &pipex);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_child(&pipex, argv, envp);
	pipex.pid2 = fork();
	waitpid(pipex.pid1, NULL, 0);
	if (pipex.pid2 == 0)
		ft_parent(&pipex, argv, envp);
	ft_close_fd(&pipex);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
