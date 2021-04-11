/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:21:08 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 15:26:34 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	if (*little == '\0')
		return ((char *)big);
	len = ft_strlen(little);
	while (*big != '\0' && n-- >= len)
	{
		if (ft_strncmp(big, little, len))
			return ((char*)big);
		big++;
	}
	return (0);
}
