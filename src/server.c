/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:42:27 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 23:42:38 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	handle_signal(int sig)
{
	static unsigned char	buffer;
	static int				bitidx;

	if (sig == SIGUSR2)
		buffer += 0x80 >> bitidx;
	bitidx++;
	if (bitidx == 8)
	{
		if (buffer == '\0')
			buffer = '\n';
		ft_putchar(buffer);
		bitidx = 0;
		buffer = '\0';
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
