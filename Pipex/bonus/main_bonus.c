/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:32:27 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/23 18:16:22 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int pipex_main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		ft_close_err("TOO FEW ARGUMENT\n");
	pipex.filein = open(argv[1], O_RDONLY);
	if (pipex.filein == -1)
		ft_close_err("ERROR WITH INFILE\n");
	pipex.fileout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fileout == -1)
		ft_close_err("ERROR WITH OUTFILE\n");
	if (pipe(pipex.fd) == -1)
		ft_close_err("ERROR PIPE\n");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		ft_close_err("ERROR\n");
	if (pipex.pid1 == 0)
		ft_child(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		ft_close_err("ERROR\n");
	waitpid(pipex.pid1, NULL, 0);
	if (pipex.pid2 == 0)
		ft_parent(&pipex, argv, envp);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(pipex.pid2, NULL, 0);
	//free_finish(&pipex);
	printf("SUCCES!\n");
	return(0);
}

int		main(int argc, char **argv, char **envp)
{
	t_pipexb	pb;

	if (argc < 5)
		ft_close_err("TOO FEW ARGUMENT\n");
	if ((check_arg(argv[1], &pb) == 0) && argc == 5)
		pipex_main(argc, argv, envp);
	else
		{
			if (pb.hd_count > 0)
				{
					here_doc();
					//pipex avc heredoc
				}
			else
				{
					printf("MULT CMD\n");
					//pipex avc plusier cmd
				} 
		}

	return (0);
}