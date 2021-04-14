/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:00:22 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/11 11:02:01 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	in_s(char c, char *str)
{
	int		i;

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
	int		count;
	int		is_word;

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

int	ft_arr(int *arr)
{
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	return (*arr);
}

char	**ft_ssplit(char *s, char *set)
{
	char		**tab;
	int			arr[3];

	*arr = ft_arr(arr);
	tab = malloc(sizeof(char *) * (count_words(s, set) + 1));
	if (!tab)
		return (NULL);
	while (s[++arr[0]])
	{
		if (!in_s(s[arr[0]], set))
		{
			if (arr[2] == 0)
				tab[arr[1]] = malloc(sizeof(char) * w_s(s, arr[0], set) + 1);
			if (arr[2] == 0 && !tab)
				return (NULL);
			tab[arr[1]][arr[2]] = s[arr[0]];
			tab[arr[1]][++arr[2]] = '\0';
		}
		if ((in_s(s[arr[0]], set) && !in_s(s[arr[0] + 1], set) && arr[2] > 0))
			arr[1]++;
		if ((in_s(s[arr[0]], set) && !in_s(s[arr[0] + 1], set) && arr[2] > 0))
			arr[2] = 0;
	}
	tab[count_words(s, set)] = NULL;
	return (tab);
}
