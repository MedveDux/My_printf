/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:35 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/11 20:00:12 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_con(char *arg, va_list ptr)
{
	int	size;

	size = 0;
	if (*arg == 'c')
		size += ft_putchar_fd_printf(va_arg(ptr, int), 1);
	else if (*arg == 's')
		size += ft_putstr_fd_printf(va_arg(ptr, char *), 1);
	else if (*arg == 'p')
	{
		size += write (1, "0x", 2);
		size += ft_putp_fd_printf(va_arg(ptr, unsigned long int), 1);
	}
	else if (*arg == 'd' || *arg == 'i')
		size += ft_putdecimal_printf(va_arg(ptr, int));
	else if (*arg == 'u')
		size += ft_putunsigned_printf(va_arg(ptr, unsigned int));
	else if (*arg == 'x')
		size += ft_putx_fd_printf(va_arg(ptr, unsigned int), 1);
	else if (*arg == 'X')
		size += ft_putxx_fd_printf(va_arg(ptr, unsigned int), 1);
	else if (*arg == '%')
		size += write (1, "%", 1);
	return (size);
}

int	ft_printf(const char *arg, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	i = -1;
	len = 0;
	va_start(ptr, arg);
	while (arg[++i])
	{
		if (arg[i] == '%' && arg[i])
		{
			len += ft_con((char *)(&arg[i + 1]), ptr);
			++i;
		}
		else
			len += write (1, &arg[i], 1);
	}
	va_end (ptr);
	return (len);
}

