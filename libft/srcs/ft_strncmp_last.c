/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:21:20 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/08 14:31:54 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp_last(const char *s1, const char *s2, size_t n)
{
	size_t	i;
    int     j;
    int     k;

    n++;
    j = ft_strlen(s1);
    k = ft_strlen(s2);
	i = 0;
	while (s1[j] == s2[k] && i < n && s1[i] != '\0')
    {
		i++;
        j--;
        k--;
    }
	if (i == n || !s1 || !s2)
		return (0);
	return ((unsigned char)s1[j] - (unsigned char)s2[k]);
}