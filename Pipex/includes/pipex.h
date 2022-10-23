/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:23:50 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/21 11:40:40 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PIPEX_H
# define	PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
    int		fd[2];
	int		filein;
	int		fileout;
	char	**cmd;
	char	*cmd_path;
	char	**paths;
	pid_t	pid1;
	pid_t	pid2;
}		t_pipex;

//--------------CLOSE---------------//
void	ft_close_err(char *str);
void	free_process(char **tmp);
void	free_finish(t_pipex *pipex);

//-------------PROCESS-------------//
void	ft_child(t_pipex *pipex, char **argv, char **envp);
void	ft_parent(t_pipex *pipex, char **argv, char **envp);

//-------------UTILS------------------//
//char    *get_path(t_pipex *pipex, char *cmd, char **envp);
//char	*get_cmd(char **paths, char *cmd);
void    *get_path(t_pipex *pipex, char *cmd, char **envp);
void	*get_cmd(t_pipex *pipex, char *cmd);


#endif