/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:10:15 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/10 11:41:01 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_intlen(int n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_check(char *str, int i, int fac, int atof)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		fac *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	return (atof);
}

float	ft_atof(char *str)
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;

	fac = 1;
	atof = 0;
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-')
		fac = -1;
	atoi = ft_atoi(str);
	i = ft_intlen(atoi);
	if (fac == -1)
		 i++;
	if (str[i] != '.')
		return (atoi);
	i++;
	atof = ft_check(str, i, fac, atof);
	atof = atof / fac;
	return (atoi + atof);
}
