/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:29:05 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/02/03 17:30:43 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	ft_send_msg(int pid, char *str)
{
	int	i;
	int	bits;

	i = -1;
	while (str[++i])
	{
		bits = 8;
		while (--bits >= 0)
		{	
			if ((str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	bits = 8;
	while (--bits >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(10);
	}
}

int	ft_errors(int argc, char **argv)
{
	int	exit;
	int	i;

	exit = 0;
	i = -1;
	if (argc != 3)
		exit = ft_printf("Wrong number of arguments.\n");
	else
	{
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]))
				exit = ft_printf("PID is composed of DIGITS only.\n");
	}
	return (exit);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (ft_errors(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	ft_send_msg(pid, str);
	free(str);
	return (0);
}
