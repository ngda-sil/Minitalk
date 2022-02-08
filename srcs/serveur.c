/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:29:45 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/02/03 18:17:42 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	ft_print_msg(int sig)
{
	static int	bits;
	static int	c;

	if (bits <= 7)
	{
		c <<= 1;
		if (sig == SIGUSR1)
			c ^= 1;
		++bits;
	}
	if (bits == 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_print_msg);
	signal(SIGUSR2, ft_print_msg);
	while (1)
		pause();
	return (0);
}
