/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:00:22 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/10 12:48:32 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	in_s(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_words(char const *s, char *set)
{
	int	count;
	int	is_word;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (in_s(*s, set))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	w_s(char const *s, int pos, char *set)
{
	size_t	len;

	len = 0;
	while (s[pos])
	{
		if (in_s(s[pos], set))
			return (len);
		len++;
		pos++;
	}
	return (len);
}

static void	*ft_close(char **tab, char *s, char *set)
{
	tab[count_words(s, set)] = NULL;
	return (tab);
}

char	**ft_ssplit(char const *s, char *set)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (count_words(s, set) + 1));
	if (!tab)
		return (NULL);
	while (s[++i])
	{
		if (!in_s(s[i], set))
		{
			if (k == 0)
			{
				tab[j] = malloc(sizeof(char) * w_s(s, i, set) + 1);
				if (!tab)
					return (NULL);
			}
			tab[j][k] = s[i];
			tab[j][++k] = '\0';
		}
		k = 0;
		if ((in_s(s[i], set) && !in_s(s[i + 1], set) && k > 0) == 0)
			j++;
	}
	ft_close(tab, s, set);
}
