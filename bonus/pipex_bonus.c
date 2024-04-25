/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:05:21 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/09 19:52:42 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	first_child(int *fd, char **av)
{
	int	in_fd;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
		return (msg_error("Error", strerror(errno)));
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	return (0);
}

int	last_child(int *fd, int prev_fd, int len, char **av)
{
	int	out_fd;

	close(fd[1]);
	close(fd[0]);
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	out_fd = open(av[len - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		return (msg_error("Error", strerror(errno)));
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	return (0);
}

int	other_child(int *fd, int prev_fd)
{
	close(fd[0]);
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return (0);
}

void	process_child(int i, char **av, int *fd, int prev_fd)
{
	int	len;

	len = tab_len(av);
	if (i == 2)
		first_child(fd, av);
	else if (i == len - 2)
		last_child(fd, prev_fd, len, av);
	else
		other_child(fd, prev_fd);
}

int	pipex(int ac, char **av, char **envp)
{
	int		i;
	int		prev_fd;
	int		fd[2];
	pid_t	pid;

	i = 1;
	prev_fd = -1;
	while (++i < ac - 1)
	{
		if (pipe(fd) < 0)
			return (msg_error("Error", "Pipe failed"));
		pid = fork();
		if (pid < 0)
			return (msg_error("Error", "Fork failed"));
		if (pid == 0)
		{
			process_child(i, av, fd, prev_fd);
			exec_command(av[i], envp);
		}
		else
			prev_fd = save_fd(fd, prev_fd);
	}
	wait_child(1, ac);
	return (close_fd(fd, prev_fd), 0);
}
