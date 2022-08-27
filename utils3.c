/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:39:49 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/25 14:44:48 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

static int	nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (1)
	{
		n /= 10;
		if (n == 0)
			return (i);
		i++;
	}
}

static char	*ft_itoa(int n)
{
	char	*nbr;
	int		n_is_neg;
	int		i;

	i = nbrlen(n);
	nbr = malloc(i + 1);
	if (nbr != NULL)
	{
		n_is_neg = n < 0;
		nbr[i--] = '\0';
		while (1)
		{
			if (n_is_neg)
				nbr[i] = n % 10 * -1 + '0';
			else
				nbr[i] = n % 10 + '0';
			n /= 10;
			i--;
			if (n == 0)
				break ;
		}
		if (n_is_neg)
			nbr[i] = '-';
	}
	return (nbr);
}

static void	ft_putnbr(int n)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (nbr != NULL)
		ft_putstr(nbr);
	free(nbr);
}

void	ft_putnbrln(int n)
{
	ft_putnbr(n);
	ft_putchar('\n');
}
