#include <signal.h>
#include "./ft_printf/ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:13:38 by cfiestas          #+#    #+#             */
/*   Updated: 2023/01/16 17:41:51 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign < 0)
		num *= -1;
	return (num);
}

static void send_bit(int pid, char c)
{
	int i;
	int bit;

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
			if (kill(pid, SIGUSR2)== -1)
				exit(EXIT_FAILURE);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	int pid;

	if (ac != 3)
		exit(EXIT_FAILURE);

	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_bit(pid, av[2][i++]);
	send_bit(pid, av[2][i]);

	while(1)
		pause();
	return (0);
}
