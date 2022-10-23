/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:07:37 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/23 18:13:57 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(void)
{
	while(1)
	{
		write(1, "boumadj pipex - heredoc> ", 25);
		return ;
	}
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