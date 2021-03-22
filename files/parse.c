/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:40:18 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/22 18:56:59 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"
#include <stdio.h>

int check_type(t_global *a, char **words)
{
    if (*words[0] == 'R')
        parse_resolution(a, words);
    if (*words[0] == 'A')
        parse_ambient(a, words);
    if (*words[0] == 'c')
        parse_camera(a, words);
    if (*words[0] == 'l')
        parse_light(a, words);
    return (0);
}

int parse(t_global *a, char *path, int bmp)
{
    a->line = 0;
    bmp = 0;
    if ((a->fd = open(path, O_RDONLY)) < 0)
        ft_putstr("Error can't open the scene rt file");
    while(get_next_line(a->fd, &a->line) > 0)
    {
        a->split = ft_ssplit(a->line, " \t\v\n\r\f");
        if (a->split[0])
            check_type(a, a->split);
    }

    close(a->fd);
    return (0);
}

int parse_resolution(t_global *a, char **words)
{
    int width;
    int height;

    width = ft_atoi(words[1]);
    height = ft_atoi(words[2]);
    if (width < 0 || height < 0)
    {
        ft_putstr("Error resolution in rt file");
        exit(0);
    }
    a->width = width;
    a->height = height;
    if (width > MAX_WIDTH)
        a->width = MAX_WIDTH;
    if (height > MAX_HEIGHT)
        a->height = MAX_HEIGHT;
    return (0);
}
///cleean to make
int parse_ambient(t_global *a, char **words)
{
    a->t = 1;
    words = 0;
    return (0);
}

int parse_light(t_global *a, char **words)
{
        words = 0;

    a->t = 1;
    return (0);
}

int parse_camera(t_global *a, char **words)
{
    words = 0;
    a->t = 1;
    return (0);
}