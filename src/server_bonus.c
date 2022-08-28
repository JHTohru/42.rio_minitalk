/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:13:05 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 23:45:09 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

static int	code_point_len(char *cp)
{
	if ((cp[0] & 0x80) == 0)
		return (1);
	if ((cp[0] & 0xE0) == 0xC0)
		return (2);
	if ((cp[0] & 0xF0) == 0xE0)
		return (3);
	return (4);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	buffer[4];
	static int	bitidx;

	(void)context;
	if (sig == SIGUSR2)
		buffer[bitidx / 8] |= 0x80 >> bitidx % 8;
	if (++bitidx % 8 == 0)
	{
		if (bitidx / 8 == code_point_len(buffer))
		{
			if (buffer[0] == '\0')
			{
				buffer[0] = '\n';
				kill(info->si_pid, SIGUSR1);
			}
			ft_putnstr(buffer, code_point_len(buffer));
			bitidx = 0;
			buffer[0] = '\0';
		}
		else
		{
			buffer[bitidx / 8] = 0x80;
			bitidx += 2;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbrln((int)getpid());
	while (1)
		pause();
	return (0);
}
