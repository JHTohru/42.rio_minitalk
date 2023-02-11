/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:25:54 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 02:20:30 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	magnitude(int n)
{
	int	mag;

	mag = 1;
	while ((n / 10) != 0)
	{
		mag *= 10;
		if (n < 0)
			n /= -10;
		else
			n /= 10;
	}
	return (mag);
}	

void	ft_putnbr(int n)
{
	int		mag;
	int		n_is_negative;

	n_is_negative = n < 0;
	if (n_is_negative)
		ft_putchar('-');
	mag = magnitude(n);
	while (mag != 0)
	{
		if (n_is_negative)
			ft_putchar('0' - (n / mag));
		else
			ft_putchar('0' + (n / mag));
		n %= mag;
		mag /= 10;
	}
}
