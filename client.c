/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoutar- <hkoutar-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:32:41 by hkoutar-          #+#    #+#             */
/*   Updated: 2023/05/06 16:47:35 by hkoutar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char *msg)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	while (*(msg + i))
	{
		j = 0;
		while (j < 8)
		{
			n = 128 >> j;
			if ((n & *(msg + i)) == 0)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		exit (1);
	pid = ft_atoi(*(av + 1));
	if (pid <= 0)
		exit (1);
	ft_send(pid,*(av + 2));
	return (0);
}
