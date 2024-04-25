/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:43:21 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/09 19:52:35 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	first_child_here_doc(int prev_fd, int *fd)
{
	close(fd[0]);
	prev_fd = open("heredoc.tmp", O_RDONLY);
	if (prev_fd < 0)
		return (msg_error("Error", strerror(errno)));
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	unlink("heredoc.tmp");
	return (0);
}

int	last_child_here_doc(int *fd, int prev_fd, int ac, char **av)
{
	int	out_fd;

	close(fd[0]);
	close(fd[1]);
	out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (out_fd < 0)
		return (msg_error("Error", strerror(errno)));
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	return (0);
}

int	other_child_here_doc(int *fd, int prev_fd)
{
	close(fd[0]);
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return (0);
}

void	process_child_here_doc(int i, char **av, int *fd, int prev_fd)
{
	int	len;

	len = tab_len(av);
	if (i == 3)
		first_child_here_doc(prev_fd, fd);
	else if (i == len - 2)
		last_child_here_doc(fd, prev_fd, len, av);
	else
		other_child_here_doc(fd, prev_fd);
}

int	here_doc(int ac, char **av, char **envp)
{
	int		i;
	int		prev_fd;
	int		fd[2];
	pid_t	pid;

	i = 2;
	prev_fd = -1;
	get_here_doc(av);
	while (++i < ac - 1)
	{
		if (pipe(fd) == -1)
			return (msg_error("Error", "Pipe failed"));
		pid = fork();
		if (pid < 0)
			return (msg_error("Error", "Fork failed"));
		if (pid == 0)
		{
			process_child_here_doc(i, av, fd, prev_fd);
			exec_command(av[i], envp);
		}
		else
			prev_fd = save_fd(fd, prev_fd);
	}
	wait_child(2, ac);
	return (close_fd(fd, prev_fd), 0);
}
