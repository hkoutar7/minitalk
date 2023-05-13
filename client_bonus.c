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

void	ft_endchar(int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		usleep(500);
		kill (pid, SIGUSR2);
		j++;
	}
}

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
	ft_endchar(pid);
}

void	ft_received(int pid, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (pid == SIGUSR1)
	{
		write(1, "Message received", 17);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
		exit (1);
	pid = ft_atoi(*(av + 1));
	if (pid <= 0)
		exit (1);
	ft_send(pid,*(av + 2));
	sa.sa_sigaction = &ft_received;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
