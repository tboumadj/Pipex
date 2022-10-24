/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:59:38 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/24 17:02:34 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void    *get_path_bonus(t_pipexb *pipex, char *cmd, char **envp)
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
	cmd_path = get_cmd_bonus(pipex, cmd);
	return (cmd_path);
}

void	*get_cmd_bonus(t_pipexb *pipex, char *cmd)
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