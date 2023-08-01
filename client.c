/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:13:38 by cfiestas          #+#    #+#             */
/*   Updated: 2023/08/01 14:45:21 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "minitalk.h"

static void	send_bit(int pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = ((c >> i) & 1);
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(2, "Error: Invalid PID", 18);
		return (-1);
	}
	i = 0;
	while (av[2][i])
		send_bit(pid, av[2][i++]);
	send_bit(pid, av[2][i]);
	return (0);
}
