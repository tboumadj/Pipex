/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:39:54 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/26 13:48:58 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*get_path(t_pipex *pipex, char *cmd, char **envp)
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
	cmd_path = get_cmd(pipex, cmd);
	return (cmd_path);
}

void	*get_cmd(t_pipex *pipex, char *cmd)
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
