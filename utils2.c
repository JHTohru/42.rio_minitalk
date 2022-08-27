/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:36:17 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/25 14:43:15 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putstr(char *str)
{
	ft_putstr_fd(STDOUT_FILENO, str);
}

void	ft_puterror(char *str)
{
	ft_putstr_fd(STDERR_FILENO, str);
}

void	ft_putnstr(char *str, size_t n)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > n)
		len = n;
	write(STDOUT_FILENO, str, len);
}
