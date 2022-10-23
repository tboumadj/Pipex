/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:26:48 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/23 17:29:40 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_child(t_pipex *pipex,char **argv, char **envp)
{	
	//int i = 0;
	pipex->cmd = ft_split(argv[2], ' '); //malloc!
	/*while (pipex->cmd[i])
	{
		printf("cmd %d = %s\n", i, pipex->cmd[i]);
		i++;
	}*/
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->filein, STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->cmd_path = get_path(pipex, pipex->cmd[0], envp);
	if (!pipex->cmd_path)
	{
		free_process(pipex->cmd);
		ft_close_err("ERROR\n");
	}
	execve(pipex->cmd_path, pipex->cmd, envp);
	//verifier avec if si commande possible sinon BUG
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
		ft_close_err("ERROR\n");
	}
	execve(pipex->cmd_path, pipex->cmd, envp);
	//verifier avec if si commande possible sinon BUG
}

void    *get_path(t_pipex *pipex, char *cmd, char **envp)
{
	char	*envp_path;
	char	*cmd_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH", 4);
		if (envp_path)
		{
			envp_path = ft_substr(envp_path, 4, 777); //malloc!
			break;
		}
		i++;
	}
	pipex->paths = ft_split(envp_path, ':'); //malloc!
	free(envp_path);
	cmd_path = get_cmd(pipex, cmd);
	return (cmd_path);
}

void	*get_cmd(t_pipex *pipex, char *cmd)
{
	int	i;
	char	*cmd_path;
	
	i = 0;
	while(pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin(pipex->paths[i], "/"); //malloc!
		i++;
	}
	i = 0;
	while (pipex->paths[i])
	{
		cmd_path = ft_strjoin(pipex->paths[i], cmd); //malloc!
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return(cmd_path);
}