/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:40:18 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/23 11:51:39 by liafigli         ###   ########.fr       */
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
///si moltiplicherá per la luce, ovvero luce ambientale per luce normale
int parse_ambient(t_global *a, char **words)
{   
    char **split;
    t_color col;
    
    a->range = ft_atof(words[1]);
    split = ft_split(words[2], ',');
    
    col.r = atof(split[0]) / 255;
	col.g = atof(split[1]) / 255;
	col.b = atof(split[2]) / 255;
    a->color = col;
    
    if (a->range > 1 || a->range < 0)
        ft_putstr("Error ambient in rt file");
    return (0);
}

int parse_light(t_global *a, char **words)
{
    char **origin;
    char **color;
    t_color col;
    t_light light;

    origin = ft_split(words[1], ',');
    light.origin.x = ft_atoi(origin[0]);
    light.origin.y = ft_atoi(origin[1]);
    light.origin.z = ft_atoi(origin[2]);
    light.range = ft_atof(words[1]);

    color = ft_split(words[2], ',');
    
    col.r = atof(color[0]) / 255;
	col.g = atof(color[1]) / 255;
	col.b = atof(color[2]) / 255;
    light.color = col;
    return (0);
}

int parse_camera(t_global *a, char **words)
{
    t_camera camera;
    char **position;
    char **direction;

    position = ft_split(words[1], ',');
    camera.position.x = ft_atoi(position[0]);
    camera.position.y = ft_atoi(position[1]);
    camera.position.z = ft_atoi(position[2]);

    direction = ft_split(words[2], ',');
    camera.direction.x = ft_atoi(direction[0]);
    camera.direction.y = ft_atoi(direction[1]);
    camera.direction.z = ft_atoi(direction[2]);

    camera.fov = ft_atoi(words[3]);
    return (0);
}