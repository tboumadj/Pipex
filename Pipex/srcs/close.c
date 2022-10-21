/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:15:56 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/19 18:31:23 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_process(char **tmp)
{
	int	i;

	i = -1;

	while(tmp[++i])
		free(tmp[i]);
	free(tmp);
}

void	free_finish(t_pipex *pipex)
{
	int	i;

	i = -1;

	while (pipex->cmd[++i])
	{
		free(pipex->cmd[i]);
		//i++;
	}
	//printf("i = %d\n", i);
	//if(pipex->cmd)
	//	free(pipex->cmd);
	/*i = 0;
	while (pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	printf("i2 = %d\n", i);*/
	//free(pipex->paths);
	//free(pipex->cmd_path);
}