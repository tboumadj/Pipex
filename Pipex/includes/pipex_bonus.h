/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:33:01 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/27 11:51:04 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <errno.h>
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
	int		i;
	int		arc;
	pid_t	lpid;
}		t_pipexb;

//-----------------PIPEX------------------//
int		pipex_main(int argc, char **argv, char **envp);
void	ft_child(t_pipex *pipex, char **argv, char **envp);
void	ft_parent(t_pipex *pipex, char **argv, char **envp);
void	*get_path(t_pipex *pipex, char *cmd, char **envp);
void	*get_cmd(t_pipex *pipex, char *cmd);
void	ft_close_err_nor(char *str, t_pipex *piepx);
void	ft_close_err(char *str);
void	free_process(char **tmp);
void	ft_close_fd(t_pipex *pipex);
void	ft_close_err_exec(char *str, t_pipex *pipex);

//-----------------BONUS------------------//
int		check_arg(char *argv1, t_pipexb *pb);
void	here_doc(t_pipexb *pb, char *cmd);
void	road_hd(t_pipexb *pb, char *cmd, char **envp);
void	create_proc(t_pipexb *pb, char *argv, char **envp);
void	child_bonus(t_pipexb *pb, char *argv, char **envp);
void	*get_path_bonus(t_pipexb *pipex, char *cmd, char **envp);
void	*get_cmd_bonus(t_pipexb *pipex, char *cmd);
void	ft_else(t_pipexb *pb, char *argv1, char *lastargv);
void	ft_close_err_exec_bon(char *str, t_pipexb *pb);
void	ft_close_fd_bon(t_pipexb *pb);
void	ft_close_err_bn(char *str, t_pipexb *pb);

#endif