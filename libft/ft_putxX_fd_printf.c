/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxX_fd_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:18:18 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/08 16:18:46 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putxX_fd_printf( int n, int fd)
{
	int		size;
	int		i;
	char	s[17];

	i = 0;
	size = 0;
	if (n == 0)
		return (ft_putchar_fd_printf(('0'), fd));
	while (n > 0)
	{
		if ((n % 16) < 10)
			s[i] = ((n % 16) + '0');
		else
			s[i] = ((n % 16) + 55);
		i++;
		n = n / 16;
	}
	s[i] = '\0';
	return (ft_back(s, i));
}
