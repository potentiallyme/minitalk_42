/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:02:22 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/15 19:01:26 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_or;

static int	bin_tr(char c, int pid)
{
	static int	i;
	static int	j;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_or == 0)
		{
			if (j == 100)
			{
				exit(0);
			}
			j++;
			usleep(1200);
		}
		g_or = 0;
		j = 0;
	}
	return (0);
}

static void	all_g(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	(void)sig;	
	g_or = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	s_sig;
	int					pid;
	int					i;

	if (ac != 3 || !av[1] || !av[2])
		return (1);
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_sigaction = all_g;
	sigemptyset(&s_sig.sa_mask);
	sigaction(SIGUSR1, &s_sig, NULL);
	pid = atoi(av[1]);
	i = -1;
	while (av[2][++i])
		bin_tr(av[2][i], pid);
	bin_tr('\0', pid);
	return (0);
}
