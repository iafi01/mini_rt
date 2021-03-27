/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:05:42 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/27 12:07:44 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int parse_sphere(t_global *a, char **words)
{
    t_sphere *sph;
    char **origin;
    char **color;
    t_color col;

    if (!(sph = ft_calloc(1, sizeof(t_sphere))))
		error("fail to malloc");
    origin = ft_split(words[1], ',');
    sph->origin.x = ft_atoi(origin[0]);
    sph->origin.y = ft_atoi(origin[1]);
    sph->origin.z = ft_atoi(origin[2]);

    sph->diameter = ft_atof(words[2]);

    color = ft_split(words[3], ',');
    col.r = ft_atoi(color[0]);
    col.g = ft_atoi(color[1]);
    col.b = ft_atoi(color[2]);
    sph->color = col;

    if (!check_range_color(col))
        error("Error parse color sphere");

    ft_lstadd_back(&a->lista, ft_lstnew(sph));
    return (0);
}

int parse_plane(t_global *a, char **words)
{
    t_plane *pl;
    char **center;
    char **orientation;
    char **color;
    t_color col;

    if (!(pl = ft_calloc(1, sizeof(t_plane))))
		error("fail to malloc");
    center = ft_split(words[1], ',');
    pl->center.x = ft_atof(center[0]);
    pl->center.y = ft_atof(center[1]);
    pl->center.z = ft_atof(center[2]);

    orientation = ft_split(words[2], ',');
    pl->orientation.x = ft_atoi(orientation[0]);
    pl->orientation.y = ft_atoi(orientation[1]);
    pl->orientation.z = ft_atoi(orientation[2]);

    color = ft_split(words[3], ',');
    col.r = ft_atoi(color[0]);
    col.b = ft_atoi(color[1]);
    col.g = ft_atoi(color[2]);

    if (!check_range_color(col))
        error("Error parse color plane");

    ft_lstadd_back(&a->lista, ft_lstnew(pl));
    return (0);
}

int parse_cylinder(t_global *a, char **words)
{
    t_cylinder *cy;
    char **center;
    char **color;
    t_color col;

    if (!(cy = ft_calloc(1, sizeof(t_cylinder))))
		error("fail to malloc");
    center = ft_split(words[1], ',');
    cy->center.x = ft_atof(center[0]);
    cy->center.y = ft_atof(center[1]);
    cy->center.z = ft_atof(center[2]);

    cy->range = ft_atof(words[2]);
    cy->diameter = ft_atof(words[3]);
    cy->height = ft_atof(words[4]);

    color = ft_split(words[3], ',');
    col.r = ft_atoi(color[0]);
    col.b = ft_atoi(color[1]);
    col.g = ft_atoi(color[2]);

    if (!check_range_color(col))
        error("Error parse color cylinder");
    ft_lstadd_back(&a->lista, ft_lstnew(cy));
    return (0);
}

int parse_square(t_global *a, char **words)
{
    t_square *sq;
    char **center;
    char **color;
    t_color col;

    if (!(sq = ft_calloc(1, sizeof(t_square))))
		error("fail to malloc");
    center = ft_split(words[1], ',');
    sq->center.x = ft_atof(center[0]);
    sq->center.y = ft_atof(center[1]);
    sq->center.z = ft_atof(center[2]);

    sq->range = ft_atof(words[2]);
    sq->side = ft_atof(words[3]);


    color = ft_split(words[3], ',');
    col.r = ft_atoi(color[0]);
    col.b = ft_atoi(color[1]);
    col.g = ft_atoi(color[2]);

    if (!check_range_color(col))
        error("Error parse color square");
    
    if (sq->range > 1 || sq->range < 0)
        error("Error square in rt file");

    ft_lstadd_back(&a->lista, ft_lstnew(sq));
    return (0);
}

int parse_triangle(t_global *a, char **words)
{
    t_triangle *tr;
    char **p1;
    char **p2;
    char **p3;
    char **color;
    t_color col;

    if (!(tr = ft_calloc(1, sizeof(t_triangle))))
		error("fail to malloc");
    p1 = ft_split(words[1], ',');
    tr->p1.x = ft_atof(p1[0]);
    tr->p1.y = ft_atof(p1[1]);
    tr->p1.z = ft_atof(p1[2]);

    p2 = ft_split(words[2], ',');
    tr->p2.x = ft_atof(p2[0]);
    tr->p2.y = ft_atof(p2[1]);
    tr->p2.z = ft_atof(p2[2]);

    p3 = ft_split(words[3], ',');
    tr->p3.x = ft_atof(p3[0]);
    tr->p3.y = ft_atof(p3[1]);
    tr->p3.z = ft_atof(p3[2]);

    color = ft_split(words[4], ',');
    col.r = ft_atoi(color[0]);
    col.b = ft_atoi(color[1]);
    col.g = ft_atoi(color[2]);

    if (!check_range_color(col))
        error("Error parse color ambient");
        
    ft_lstadd_back(&a->lista, ft_lstnew(tr));
    return (0);
}