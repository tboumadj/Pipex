/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:33:01 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/21 07:09:31 by tboumadj@student ###   ########.fr       */
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
# include "../srcs/pipex.h"

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

int		pipex_main(int argc, char **argv, char **envp);
int		check_arg(char *argv1, t_pipexb *bonus);

#endif