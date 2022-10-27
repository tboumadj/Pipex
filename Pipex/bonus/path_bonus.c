/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:59:38 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/27 10:43:19 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	*get_path_bonus(t_pipexb *pipex, char *cmd, char **envp)
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
			envp_path = ft_substr(envp_path, 4, 777);
			break ;
		}
		i++;
	}
	pipex->paths = ft_split(envp_path, ':');
	free(envp_path);
	cmd_path = get_cmd_bonus(pipex, cmd);
	return (cmd_path);
}

void	*get_cmd_bonus(t_pipexb *pipex, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin(pipex->paths[i], "/");
		i++;
	}
	i = 0;
	while (pipex->paths[i])
	{
		cmd_path = ft_strjoin(pipex->paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (cmd_path);
}

void	ft_else(t_pipexb *pb, char *argv1, char *lastargv)
{
	pb->filein = open(argv1, O_RDONLY);
	if (pb->filein == -1)
		ft_close_err("ERROR WITH INFILE\n");
	pb->fileout = open(lastargv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pb->fileout == -1)
		ft_close_err("ERROR WITH OUTFILE\n");
	dup2(pb->filein, STDIN_FILENO);
}

void	free_process(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

void	ft_close_err_bn(char *str, t_pipexb *pb)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(str, 2);
	ft_close_fd_bon(pb);
	exit(EXIT_FAILURE);
}
