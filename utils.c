/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:43 by cfiestas          #+#    #+#             */
/*   Updated: 2023/08/01 14:42:00 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

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

int	ft_putnbr(int nbr, char *base)
{
	int				count;
	unsigned int	j;
	unsigned int	len;

	count = 0;
	len = ft_strlen(base);
	j = nbr;
	if (j >= len)
		count += ft_putnbr(j / len, base);
	count += write(1, &base[j % len], 1);
	return (count);
}
