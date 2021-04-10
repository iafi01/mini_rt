/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:21:20 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/10 12:02:24 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;
	int	n;

	j = ft_strlen(s1);
	k = ft_strlen(s2);
	n = k + 1;
	i = 0;
	while (s1[j] == s2[k] && i < n && s1[i] != '\0')
	{
		i++;
		j--;
		k--;
	}
	if (i == n || !s1 || !s2)
		return (1);
	if ((unsigned char)s1[j] == (unsigned char)s2[k])
		return (1);
	return (0);
}
