/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:32:27 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/27 14:56:22 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	pipex_main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		ft_close_err("TOO FEW ARGUMENT");
	pipex.filein = open(argv[1], O_RDONLY);
	if (pipex.filein == -1)
		ft_close_err("ERROR WITH INFILE");
	pipex.fileout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fileout == -1)
		ft_close_err("ERROR WITH OUTFILE");
	if (pipe(pipex.fd) == -1)
		ft_close_err_nor("ERROR PIPE", &pipex);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_child(&pipex, argv, envp);
	pipex.pid2 = fork();
	waitpid(pipex.pid1, NULL, 0);
	if (pipex.pid2 == 0)
		ft_parent(&pipex, argv, envp);
	ft_close_fd(&pipex);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipexb	pb;

	pb.i = 2;
	pb.arc = argc - 3;
	if (argc < 5)
		ft_close_err("TOO FEW ARGUMENT");
	if ((check_arg(argv[1], &pb) == 0) && argc == 5)
		pipex_main(argc, argv, envp);
	else
	{
		if (pb.hd_count > 0)
		{
			pb.i++;
			road_hd(&pb, argv[2], envp);
			pb.fileout = open(argv[argc -1],
					O_WRONLY | O_CREAT | O_APPEND, 0777);
		}
		else
			ft_else(&pb, argv[1], argv[argc -1]);
		while (pb.i < argc - 2)
			create_proc(&pb, argv[pb.i++], envp);
		dup2(pb.fileout, STDOUT_FILENO);
		child_bonus(&pb, argv[argc -2], envp);
	}
	return (0);
}
