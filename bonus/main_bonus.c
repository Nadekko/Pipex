/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:12:17 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/09 19:52:38 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_free(char **s1, char **s2, char *s3)
{
	if (s1)
		free_tab(s1);
	if (s2)
		free_tab(s2);
	if (s3)
		free(s3);
}

int	msg_error(char *msg, char *strerror)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" : ", 2);
	ft_putendl_fd(strerror, 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	if (!envp || !envp[0])
		return (msg_error("Error", "No environment variables"));
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
			return (msg_error("Usage",
					"./pipex here_doc LIMITER cmd1 cmd2 .. cmdn outfile"));
		else
			here_doc(ac, av, envp);
	}
	else
	{
		if (ac < 5)
			return (msg_error("Usage",
					"./pipex file1 cmd1 cmd2 .. cmdn file2"));
		else
			pipex(ac, av, envp);
	}
	return (0);
}
