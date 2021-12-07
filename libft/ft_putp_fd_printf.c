/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_fd_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:40:01 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/07 21:02:01 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putp_fd_printf(long unsigned int n, int fd)
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
			s[i] = ((n % 16) + 87);
		i++;
		n = n / 16;
	}
	s[i] = '\0';
	return (ft_back(s, i));
}

int	ft_back(char *s, int i)
{
	int	size;

	size = i;
	while (i >= 0)
	{
		write (1, &s[i], 1);
		i--;
	}
	return (size);
}