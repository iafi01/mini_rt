/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:05:09 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 11:23:39 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count(int n)
{
	size_t	d;

	d = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	size_t		i;
	char		*str;
	int			sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = 1;
	sign = 0;
	if (sign == 1)
		n *= -1;
	i = ft_count(n);
	str = (char *)malloc(i + sign + 1);
	if (!str)
		return (0);
	str[i + sign] = '\0';
	while (i > 0)
	{
		str[--i + sign] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
