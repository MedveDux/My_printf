/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:01:18 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/04 20:02:51 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
			i++;
		}
	}
	return (i);
}
