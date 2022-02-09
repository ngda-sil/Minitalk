/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:29:45 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/02/03 17:17:20 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

void	ft_print_msg(int sig, siginfo_t *info, void *context)
{
	static int	bits;
	static int	c;
	pid_t		pid_client;

	(void)context;
	pid_client = info->si_pid;
	if (bits <= 7)
	{
		c <<= 1;
		if (sig == SIGUSR1)
			c ^= 1;
		++bits;
	}
	if (bits == 8)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(pid_client, SIGUSR1);
		}
		else
			write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_print_msg;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
