/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:39:44 by jmenezes          #+#    #+#             */
/*   Updated: 2022/08/27 01:41:28 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_atoi(const char *nbr);

int		ft_isdigit(int c);

int		ft_isspace(int c);

void	ft_putchar(char c);

void	ft_puterror(char *str);

void	ft_putnbr(int n);

void	ft_putnbrln(int n);

size_t	ft_strlen(char *str);

#endif
