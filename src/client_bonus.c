/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:41:24 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 02:25:37 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	send_message(pid_t srvpid, char *msg)
{
	int	i;
	int	sig;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (*msg & (0x80 >> i))
				sig = SIGUSR2;
			else
				sig = SIGUSR1;
			kill(srvpid, sig);
			i++;
			usleep(1000);
		}
		if (*msg == '\0')
			break ;
		msg++;
	}
}

static void	handle_signal(int sig)
{
	(void)sig;
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_puterror("invalid number of arguments\n");
		return (1);
	}
	signal(SIGUSR1, handle_signal);
	send_message((pid_t)ft_atoi(argv[1]), argv[2]);
	pause();
	return (0);
}
