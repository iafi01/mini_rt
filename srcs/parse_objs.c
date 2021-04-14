/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:25:56 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/11 14:28:59 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	parse_sphere(t_mini_rt *rt)
{
	t_element	*sphere;
	int			check;

	check = count_split(rt->split);
	sphere = ft_calloc(1, sizeof(t_element));
	if (!sphere)
		handle_error("fail to malloc", rt);
	if (check < 4 || check > 6 || !check_split(rt->split, 5) || \
		(check == 6 && (!ft_strcmp(rt->split[5], "raiiinbow"))))
		free(sphere);
	if (check < 4 || check > 6 || !check_split(rt->split, 5) || \
		(check == 6 && (!ft_strcmp(rt->split[5], "raiiinbow"))))
		handle_error("sphere parsing error", rt);
	sphere->id = 1;
	sphere->point = split_vec(rt->split[1], rt, 0);
	sphere->diameter = ft_atof(rt->split[2]);
	if (ft_strcmp(rt->split[3], ".xpm"))
		create_texture(rt, sphere, rt->split[3]);
	else
		sphere->color = split_rgb(rt->split[3], rt);
	if (check >= 5)
		sphere->ref = ft_atof(rt->split[4]);
	if (check == 6 && ft_strcmp(rt->split[5], "raiiinbow"))
		sphere->rainbow = 1;
	ft_lstadd_back(&rt->objs_list, ft_lstnew(sphere));
	if (sphere->diameter < 0)
		handle_error("sphere parsing error", rt);
}

void	parse_plane(t_mini_rt *rt)
{
	t_element	*plane;
	int			check;

	check = count_split(rt->split);
	plane = ft_calloc(1, sizeof(t_element));
	if (!plane)
		handle_error("fail to malloc", rt);
	if (check < 4 || check > 6 || !check_split(rt->split, 5) || \
		(check == 6 && !ft_strcmp(rt->split[5], "raiiinbow")))
	{
		free(plane);
		handle_error("plane parsing error", rt);
	}
	plane->id = 2;
	plane->point = split_vec(rt->split[1], rt, 0);
	plane->orient = split_vec(rt->split[2], rt, 1);
	plane->color = split_rgb(rt->split[3], rt);
	if (check >= 5)
		plane->ref = ft_atof(rt->split[4]);
	if (check == 6 && ft_strcmp(rt->split[5], "raiiinbow"))
		plane->rainbow = 1;
	ft_lstadd_back(&rt->objs_list, ft_lstnew(plane));
}

void	parse_square(t_mini_rt *rt)
{
	t_element	*square;
	int			check;

	check = count_split(rt->split);
	square = ft_calloc(1, sizeof(t_element));
	if (!square)
		handle_error("fail to malloc", rt);
	if (check < 5 || check > 7 || !check_split(rt->split, 6) || \
		(check == 7 && !ft_strcmp(rt->split[6], "raiiinbow")))
	{
		free(square);
		handle_error("square parsing error", rt);
	}
	square->id = 3;
	square->point = split_vec(rt->split[1], rt, 0);
	square->orient = split_vec(rt->split[2], rt, 1);
	square->height = ft_atof(rt->split[3]);
	square->color = split_rgb(rt->split[4], rt);
	if (check >= 6)
		square->ref = ft_atof(rt->split[5]);
	if (check == 7 && ft_strcmp(rt->split[6], "raiiinbow"))
		square->rainbow = 1;
	ft_lstadd_back(&rt->objs_list, ft_lstnew(square));
	if (square->height < 0)
		handle_error("square parsing error", rt);
}

void	parse_cylindre(t_mini_rt *rt)
{
	t_element	*cylinder;
	int			check;

	check = count_split(rt->split);
	cylinder = ft_calloc(1, sizeof(t_element));
	if (!cylinder)
		handle_error("fail to malloc", rt);
	if (check < 6 || check > 8 || !check_split(rt->split, 7) || \
		(check == 8 && !ft_strcmp(rt->split[7], "raiiinbow")))
		free(cylinder);
	if (check < 6 || check > 8 || !check_split(rt->split, 7) || \
		(check == 8 && !ft_strcmp(rt->split[7], "raiiinbow")))
		handle_error("cylinder parsing error", rt);
	cylinder->id = 4;
	cylinder->point = split_vec(rt->split[1], rt, 0);
	cylinder->orient = vec_normalize(split_vec(rt->split[2], rt, 1));
	cylinder->diameter = ft_atof(rt->split[3]);
	cylinder->height = ft_atof(rt->split[4]);
	cylinder->color = split_rgb(rt->split[5], rt);
	if (check >= 7)
		cylinder->ref = ft_atof(rt->split[6]);
	if (check == 8 && ft_strcmp(rt->split[7], "raiiinbow"))
		cylinder->rainbow = 1;
	ft_lstadd_back(&rt->objs_list, ft_lstnew(cylinder));
	if (cylinder->height < 0 || cylinder->diameter < 0)
		handle_error("cylinder parsing error", rt);
	create_circle(rt, cylinder, cylinder->height / 2 - 0.1, 1);
}

void	parse_triangle(t_mini_rt *rt)
{
	t_element	*triangle;
	int			check;

	check = count_split(rt->split);
	triangle = ft_calloc(1, sizeof(t_element));
	if (!triangle)
		handle_error("fail to malloc", rt);
	if (check < 5 || check > 7 || !check_split(rt->split, 6) || \
		(check == 7 && !ft_strcmp(rt->split[6], "raiiinbow")))
	{
		free(triangle);
		handle_error("triangle parsing error", rt);
	}
	triangle->id = 5;
	triangle->point = split_vec(rt->split[1], rt, 0);
	triangle->point2 = split_vec(rt->split[2], rt, 0);
	triangle->point3 = split_vec(rt->split[3], rt, 0);
	triangle->color = split_rgb(rt->split[4], rt);
	triangle->orient = vec_normalize(vec_cross(vec_sub(triangle->point2, \
		triangle->point), vec_sub(triangle->point3, triangle->point)));
	if (check >= 6)
		triangle->ref = ft_atof(rt->split[5]);
	if (check == 7 && ft_strcmp(rt->split[6], "raiiinbow"))
		triangle->rainbow = 1;
	ft_lstadd_back(&rt->objs_list, ft_lstnew(triangle));
}
