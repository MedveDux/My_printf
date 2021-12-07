/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:35 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/07 21:15:01 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_con(char *arg, va_list ptr)
{
	int	size;

	size = 0;
	if (*arg == 'c')
	{
		size += ft_putchar_fd_printf(va_arg(ptr, int), 1);
	}
	else if (*arg == 's')
	{
		size += ft_putstr_fd_printf(va_arg(ptr, char *), 1);
	}
	else if (*arg == 'p')
	{
		size += write (1, "0x", 2);
		size += ft_putp_fd_printf(va_arg(ptr, long unsigned int), 1);
	}
	else if (*arg == 'p')
	{
		size 
	}
	return (size);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ptr;
	int		i;
	int		len;

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
	printf("\n{%d}", len);
	return (len);
}


int	main()
{
	int	i;
	int	*b;

	i = 0;
	// b = &i;
	ft_printf("%c  %p", 'c', b);
	printf("%c  %p", 'c', b);
	return 0;
}
