/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:31:29 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/24 11:04:40 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *s)
{
	size_t		i;
	size_t		neg;
	float		nb;

	neg = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\r'
			|| s[i] == '\f' || s[i] == '\n')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	nb = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		nb = (nb * 10) + s[i] - 48;
		i++;
	}
	if (neg)
		nb = -nb;
	return (nb);
}