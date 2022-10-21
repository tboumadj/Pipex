/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:07:37 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/21 07:09:46 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		check_arg(char *argv1, t_pipexb *bonus)
{
	if(argv1 && (ft_strncmp("here_doc", argv1, 8) == 0))
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