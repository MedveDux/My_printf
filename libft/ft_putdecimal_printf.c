/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:47 by cyelena           #+#    #+#             */
/*   Updated: 2021/12/08 16:47:27 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_minus(int num)
{
	int	len_num;

	len_num = 0;
	if (num == 0)
		len_num = 1;
	if (num < 0)
	{
		len_num++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len_num++;
	}
	return (len_num);
}

static int	ft_print(char *s)
{
	int	k;

	k = 0;
	while (s[k])
	{
		write (1, &s[k], 1);
		k++;
	}
	free (s);
	return (k);
}

int	ft_putdecimal_printf(int n)
{
	int		l;
	long	num;
	char	*s;

	num = (long)n;
	l = ft_minus(n);
	s = malloc(l + 1);
	if (!s)
		return (0);
	s[l] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
		s[0] = '0';
	l--;
	while (l >= 0 && num != 0)
	{
		s[l] = num % 10 + '0';
		num = num / 10;
		l--;
	}
	return (l = ft_print(s));
}
