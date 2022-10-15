/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:39:54 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/15 23:14:49 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(t_pipex *pipex, char *cmd, char **envp)
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
	cmd_path = get_cmd(pipex->paths, cmd);
	return (cmd_path);
}

char	*get_cmd(char **paths, char *cmd)
{
	int	i;
	char	*cmd_path;
	
	i = 0;
	while(paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/"); //malloc!
		i++;
	}
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd); //malloc!
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return(cmd_path);
}