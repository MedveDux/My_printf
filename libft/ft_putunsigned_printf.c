/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:47 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/08 16:10:31 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_printf(unsigned int n)
{
	int		i;
	char	s[11];

	i = 0;
	if (n == 0)
		return (ft_putchar_fd_printf('0', 1));
	while (n > 0)
	{
		if ((n % 10) < 10)
			s[i] = ((n % 10) + '0');
		i++;
		n = n / 10;
	}
	s[i] = '\0';
	return (ft_back(s, i));
}
