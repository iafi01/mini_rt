/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:44:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 11:08:08 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_close(char *a, char *b, size_t c)
{
	ft_strlcpy(a, b, c);
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	outstr_size;
	char			*outstr_start;
	char			*outstr_end;
	char			*outstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	outstr_start = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	if (i != -1)
		while (i >= 0 && is_in_set(s1[i], set))
			i--;
	outstr_end = (char *)&s1[i];
	if (!*s1 || outstr_end == outstr_start)
		outstr_size = 2;
	else
		outstr_size = outstr_end - outstr_start + 2;
	outstr = malloc(sizeof(char) * outstr_size);
	if (!outstr)
		return (NULL);
	return (ft_close(outstr, outstr_start, outstr_size));
}
