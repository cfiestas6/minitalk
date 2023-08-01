/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:39:02 by cfiestas          #+#    #+#             */
/*   Updated: 2023/08/01 14:41:26 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./minitalk.h"

static void	sig_handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error: failed to set signal handler\n", 37);
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = &sig_handler;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error: failed to set signal handler\n", 37);
		exit(EXIT_FAILURE);
	}
	write(1, "Server PID: ", 12);
	ft_putnbr(getpid(), "0123456789");
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
