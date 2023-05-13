/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoutar- <hkoutar-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:32:31 by hkoutar-          #+#    #+#             */
/*   Updated: 2023/05/06 16:46:09 by hkoutar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive(int signum, siginfo_t *siginfo, void *context)
{
	int			signal;
	static int	pid;
	static char	c;
	static int	i;

	(void)context;
	if (pid != siginfo->si_pid)
	{
		c = '\0';
		i = 0;
		pid = siginfo->si_pid;
	}
	if (signum == SIGUSR2)
		signal = 0;
	else
		signal = 1;
	c = c << 1;
	c = c | signal;
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		c = '\0';
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = &ft_receive;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
