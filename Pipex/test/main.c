/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:49:33 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/14 05:11:08 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	//char	*cmd_path;
	//char	*option[3] = {"ls", "-la", NULL};
	//char	*cmd = "ls";

	//(void)argc;
	//(void)argv;
    char *option[3] = {"ls", "-la", NULL};
    
    (void)argc;
    (void)argv;
    execve("/bin/ls", option, envp);
    return (0);

    	/*//---------------------------------
	cmd_path = get_path(cmd, envp);//-------TMP TEST
	//cmd_path = get_path(argv, envp);//------ TEST
	if (cmd_path)
		printf("test = %s\n", cmd_path);
	if (!cmd_path)
		{
			perror("Error!\n");
			return (-1);
		}
		execve(cmd_path, option, envp);//-----TMP TEST
		printf("victory!");
		free(cmd_path);*/
}