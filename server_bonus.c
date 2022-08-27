/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:13:05 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 00:47:29 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbrln(int n);
void	ft_putnstr(char *str, size_t n);

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

static int	update_buffer(char *buffer, int *bitidx, int bitval)
{
	if (bitval)
		buffer[*bitidx / 8] |= (0x80 >> (*bitidx % 8));
	else
		buffer[*bitidx / 8] &= (0xff - (0x80 >> (*bitidx % 8)));
	if ((*bitidx + 1) % 8 == 0)
	{
		if ((*bitidx + 1) / 8 < code_point_len(buffer))
		{
			buffer[(*bitidx + 1) / 8] = 0x80;
			*bitidx += 3;
		}
		else
		{
			*bitidx = 0;
			if (buffer[0] == '\0')
			{
				ft_putchar('\n');
				return (1);
			}
			ft_putnstr(buffer, code_point_len(buffer));
		}
	}
	else
		(*bitidx)++;
	return (0);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	buffer[4];
	static int	bitidx;

	(void)context;
	if (update_buffer(buffer, &bitidx, sig == SIGUSR2))
		kill(info->si_pid, SIGUSR1);
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
