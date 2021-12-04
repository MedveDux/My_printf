/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:40:01 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/04 21:02:17 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_printf(int n, int fd)
{
	int	i;

	i = 0;
	if (n <= -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 16, fd);
		ft_putnbr_fd(n % 16, fd);
	}
	else if (n < 0)
	{
		i += ft_putchar_fd_printf('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		i += ft_putchar_fd_printf(n + '0', fd);
	}
	return (i);
}
