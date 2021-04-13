/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:41:05 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/12 11:07:17 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	check_id_bonus(t_mini_rt *rt)
{
	if (ft_strncmp(rt->split[0], "co", 2))
		parse_cone(rt);
	else if (ft_strncmp(rt->split[0], "AA", 2) && !rt->anti_aliasing)
		parse_antialiasing(rt);
	else if (ft_strncmp(rt->split[0], "SEPIA", 5) && !rt->sepia)
		rt->sepia = 1;
	else if (ft_strncmp(rt->split[0], "STEREO", 6) && !rt->st)
		rt->st = 1;
	else if (ft_strncmp(rt->split[0], "SKY", 3) && !rt->sky)
		parse_sky(rt);
	else if (ft_strncmp(rt->split[0], "dl", 2))
		parse_dir_light(rt);
	else if (ft_strncmp(rt->split[0], "cb", 2))
		parse_cube(rt);
	else
		return (0);
	return (1);
}

void	check_id(t_mini_rt *rt)
{
	if (ft_strncmp(rt->split[0], "R", 1) && !rt->res.parsed)
		parse_res(rt);
	else if (ft_strncmp(rt->split[0], "A", 1) && !rt->ambient.parsed)
		parse_ambient(rt);
	else if (ft_strcmp(rt->split[0], "c"))
		parse_camera(rt);
	else if (ft_strncmp(rt->split[0], "l", 1))
		parse_light(rt);
	else if (ft_strncmp(rt->split[0], "sp", 2))
		parse_sphere(rt);
	else if (ft_strncmp(rt->split[0], "pl", 2))
		parse_plane(rt);
	else if (ft_strncmp(rt->split[0], "sq", 2))
		parse_square(rt);
	else if (ft_strcmp(rt->split[0], "cy"))
		parse_cylindre(rt);
	else if (ft_strncmp(rt->split[0], "tr", 2))
		parse_triangle(rt);
	else if (rt->split[0][0] == '#' || ft_strncmp(rt->split[0], "#", 1))
		;
	else if (check_id_bonus(rt))
		;
	else
		handle_error("parsing error", rt);
}

int	check_split(char **split, int max)
{
	int		i;
	int		j;

	i = 1;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (i == 3 && ft_strcmp(split[0], "sp")
				&& ft_strcmp(split[i], ".xpm"))
				break ;
			if (!ft_isdigit(split[i][j]) && split[i][j] != ',' && \
				split[i][j] != '.' && split[i][j] != '-' && (!max || i < max))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_vec	split_vec(char *str, t_mini_rt *rt, int orient)
{
	t_vec	v;
	char	**split;

	split = ft_split(str, ',');
	if (count_split(split) != 3 || ft_str_c_count(str, ',') != 2
		|| !check_split(split, 0))
	{
		free_split(split);
		handle_error("invalid vector parsing", rt);
	}
	v.x = ft_atof(split[0]);
	v.y = ft_atof(split[1]);
	v.z = ft_atof(split[2]);
	free_split(split);
	if (orient && ((v.x > 1 || v.y > 1 || v.z > 1 || v.x < -1 || v.y < -1 || \
	v.z < -1) || (!v.x && !v.y && !v.z)))
		handle_error("invalid vector parsing", rt);
	return (v);
}

t_color	split_rgb(char *str, t_mini_rt *rt)
{
	t_color	c;
	char	**split;

	split = ft_split(str, ',');
	if (count_split(split) != 3 || ft_str_c_count(str, ',') != 2
		|| !check_split(split, 0))
	{
		free_split(split);
		handle_error("invalid rgb parsing", rt);
	}
	c.r = ft_atof(split[0]) / 255;
	c.g = ft_atof(split[1]) / 255;
	c.b = ft_atof(split[2]) / 255;
	free_split(split);
	if (c.r > 1 || c.g > 1 || c.b > 1 || c.r < 0 || c.g < 0 || c.b < 0)
		handle_error("invalid rgb parsing", rt);
	return (c);
}
