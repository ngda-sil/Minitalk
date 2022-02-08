/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:29:05 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/02/03 18:33:31 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	ft_send(int pid, char *str)
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

void	ft_confirm(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("         __  __                                  \n");
		ft_printf("        | \\/  |                                 \n");
		ft_printf("	| \\  / | ___  ___ ___  __ _  __ _  ___   \n");
		ft_printf("        | |\\/| |/ _ \\/ __/ __|/ _` |/ _` |/ _ \\  \n");
		ft_printf("	| |  | |  __/\\__ \\__ \\ (_| | (_| |  __/  \n");
		ft_printf("	|_|  |_|\\___||___/___/\\__,_|\\__, |\\___|  \n");
		ft_printf("	                   _         __/ | _   _\n");
		ft_printf("	                  (_)       |___/ | | | |\n");
		ft_printf("	 _ __ ___  ___ ___ ___   _____  __| | | |\n");
		ft_printf("	|  __/ _ \\/ __/ _ \\ \\ \\ / / _ \\/ _` | | |\n");
		ft_printf("	| | |  __/ (_|  __/ |\\ V /  __/ (_| | |_|\n");
		ft_printf("	|_|  \\___|\\___\\___|_| \\_/ \\___|\\__,_| (_)\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (ft_errors(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	signal(SIGUSR1, ft_confirm);
	ft_send(pid, str);
	free(str);
	while (1)
		pause();
	return (0);
}
