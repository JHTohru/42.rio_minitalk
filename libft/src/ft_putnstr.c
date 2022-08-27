/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:16:22 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 01:16:47 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnstr(char *str, size_t n)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > n)
		len = n;
	write(STDOUT_FILENO, str, len);
}
