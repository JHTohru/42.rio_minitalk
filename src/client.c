/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:20:47 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 01:55:07 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	send_message(pid_t srvpid, char *msg)
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

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_puterror("invalid number of arguments\n");
		return (1);
	}
	send_message((pid_t)ft_atoi(argv[1]), argv[2]);
	return (0);
}
