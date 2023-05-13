/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoutar- <hkoutar-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:32:51 by hkoutar-          #+#    #+#             */
/*   Updated: 2023/05/06 01:32:53 by hkoutar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	mylongnumber ;

	if (nb < 0)
	{
		ft_putchar ('-');
		nb = nb * (-1);
	}
	mylongnumber = nb;
	if (mylongnumber >= 0 && mylongnumber <= 9)
	{
		ft_putchar(mylongnumber + 48);
	}
	else
	{
		ft_putnbr(mylongnumber / 10);
		ft_putchar((mylongnumber % 10) + 48);
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	number;
	int				signe ;
	int				i;

	number = 0;
	signe = 1;
	i = 0;
	while (*(str + i) == 32 || (*(str + i) >= 8 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			signe = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = (number * 10) + (*(str + i) - '0');
		i++;
	}
	return (number * signe);
}
