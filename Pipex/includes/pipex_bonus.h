/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:33:01 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/23 17:53:11 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PIPEX_BONUS_H
# define	PIPEX_BONUS_H

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

typedef struct s_pipexb
{
    int		fd[2];
	int		filein;
	int		fileout;
    int		hd_count;
	char	**cmd;
	char	*cmd_path;
	char	**paths;
	pid_t	pid1;
	pid_t	pid2;
}		t_pipexb;

//-----------------PIPEX------------------//
int		pipex_main(int argc, char **argv, char **envp);
void	ft_child(t_pipex *pipex,char **argv, char **envp);
void	ft_parent(t_pipex *pipex, char **argv, char **envp);
void    *get_path(t_pipex *pipex, char *cmd, char **envp);
void	*get_cmd(t_pipex *pipex, char *cmd);
void	ft_close_err(char *str);
void	free_process(char **tmp);
void	free_finish(t_pipex *pipex);

//-----------------------------------//
int		check_arg(char *argv1, t_pipexb *bonus);
void	here_doc(void);

#endif