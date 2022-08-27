/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:13:20 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/25 14:42:51 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	return (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nbr)
{
	int			sign;
	long int	n;

	while (ft_isspace(*nbr))
		nbr++;
	sign = 1;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	n = 0;
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0') * sign;
		if (sign == -1 && n > 0)
			return (0);
		else if (sign == 1 && n < 0)
			return (-1);
		nbr++;
	}
	return (n);
}
