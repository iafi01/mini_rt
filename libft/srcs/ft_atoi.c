/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:46:20 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 10:59:36 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	space(char const *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_check(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	sum;

	sum = 0;
	sign = 1;
	i = 0;
	i = space(str, i);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sum *= 10;
			sum += str[i] - '0';
			i++;
		}
		else
			break ;
	}
	if (i > 19 || sum >= 9223372036854775808ULL)
		return (ft_check(sign));
	return (sum * sign);
}
