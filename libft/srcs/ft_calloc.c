/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:03:04 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 11:00:05 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = malloc(count * size);
	if (a == NULL)
		return (NULL);
	else
	{
		ft_memset(a, 0, size * count);
		return (a);
	}
}
