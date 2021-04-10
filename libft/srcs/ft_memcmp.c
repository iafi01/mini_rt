/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:05:30 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/10 12:19:00 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*s3;
	const char		*s4;

	i = 0;
	s3 = s1;
	s4 = s2;
	while (i < n)
	{
		if (s3[i] != s4[i])
			return (((unsigned char *)s3)[i] - ((unsigned char *)s4)[i]);
		i++;
	}
	return (0);
}
