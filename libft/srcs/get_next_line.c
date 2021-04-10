/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:20:38 by rchallie          #+#    #+#             */
/*   Updated: 2021/04/10 12:09:56 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_arr(char *arr)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!arr)
		return (0);
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (0);
	}
	s = malloc(sizeof(char) * ((ft_strlen(arr) - i) + 1));
	if (!s)
		return (0);
	i++;
	while (arr[i])
		s[j++] = arr[i++];
	s[j] = '\0';
	free(arr);
	return (s);
}

char	*get_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	ft_close(char *buf)
{
	free(buf);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*arr;
	int				count;

	count = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (!checkln(arr) && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			ft_close(buf);
		buf[count] = '\0';
		arr = ft_strjoin(arr, buf);
	}
	free(buf);
	*line = get_line(arr);
	arr = get_arr(arr);
	if (count == 0)
		return (0);
	return (1);
}
