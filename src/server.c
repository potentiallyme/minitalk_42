/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:36:39 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/15 19:01:17 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	bin_tr(char *c, int sig)
{
	if (sig == SIGUSR1)
		*c = *c << 1 | 1;
	else if (sig == SIGUSR2)
		*c = *c << 1 | 0;
}

static void	all_g(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;

	(void)ucontext;
	bin_tr(&c, sig);
	i += 1;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		if (c == '\0')
			ft_printf("\n");
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_printf("    (( PID : %i ))\n", getpid());
	ft_printf("\n|******___[-:-]___******");
	ft_printf("|\n|________waiting________|\n");
	ft_printf("     ______...______\n          _____\n");
	ft_printf("            .\n            |\n\n");
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_sigaction = all_g;
	sigemptyset(&s_sig.sa_mask);
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
		pause();
	return (0);
}
