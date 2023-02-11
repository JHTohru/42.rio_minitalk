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

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buffer;
	static int				bitidx;

	(void)context;
	if (sig == SIGUSR2)
		buffer += 0x80 >> bitidx;
	bitidx++;
	if (bitidx == 8)
	{
		if (buffer == '\0')
		{
			buffer = '\n';
			kill(info->si_pid, SIGUSR1);
		}
		ft_putchar(buffer);
		bitidx = 0;
		buffer = '\0';
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
