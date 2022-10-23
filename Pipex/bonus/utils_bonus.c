/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:07:37 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/23 20:05:53 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(t_pipexb *pb, char *cmd)
{
	size_t	i;
	char	*tmp;

	i = ft_strchr(cmd, 0);
	while(1)
	{
		write(1, "boumadj pipex - heredoc> ", 25);
		tmp = get_next_line(STDIN_FILENO);
		if (!tmp)
		{
			close(pb->fd[0]);
			close(pb->fd[1]);
			exit(EXIT_FAILURE);
		}
		if (tmp[i] == '\n' && cmd && !strncmp(tmp, cmd, i))
		{
			close(pb->fd[0]);
			close(pb->fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(tmp, pb->fd[1]);
		free(tmp);
		tmp = 0;
	}
	return ;
}

int		check_arg(char *argv1, t_pipexb *bonus)
{
	if (argv1 && (ft_strncmp(argv1, "here_doc", 9) == 0))
	{
		bonus->hd_count = 1;
		return(1);
	}
	else
	{
		bonus->hd_count = 0;
		return(0);
	}
}