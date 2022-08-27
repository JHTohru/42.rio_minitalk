/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:42:27 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 00:45:03 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbrln(int n);

void	handle_signal(int sig)
{
	static char	buffer;
	static int	bitidx;

	if (sig == SIGUSR1)
		buffer &= (0xff - (0x80 >> (bitidx % 7 + 1)));
	else
		buffer |= (0x80 >> (bitidx % 7 + 1));
	bitidx++;
	if (bitidx == 7)
	{
		if (buffer == '\0')
			buffer = '\n';
		ft_putchar(buffer);
		bitidx = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR2, &handle_signal);
	ft_putnbrln((int)getpid());
	while (1)
		pause();
	return (0);
}
