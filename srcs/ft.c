/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:56:12 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/09 10:56:49 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	check_orient(t_vec *orient)
{
	if (orient->x > 1)
		orient->x = 1;
	else if (orient->x < -1)
		orient->x = -1;
	else if (orient->y > 1)
		orient->y = 1;
	else if (orient->y < -1)
		orient->y = -1;
	else if (orient->z > 1)
		orient->z = 1;
	else if (orient->z < -1)
		orient->z = -1;
	else
		return (1);
	return (0);
}

int	count_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	show_keybind(t_mini_rt *rt)
{
	if (rt->kb)
	{
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 5, 0xFFFFFF,
			"Switch Camera : TAB");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 25, 0xFFFFFF,
			"Move Camera : W,A,S,D,Q,E");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 45, 0xFFFFFF,
			"Orient Camera : T,F,G,H,R,Y");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 65, 0xFFFFFF,
			"Select Object : ENTER");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 85, 0xFFFFFF,
			"Unselect Object : \\");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 105, 0xFFFFFF,
			"Move Object : UP,LEFT,DOWN,RIGHT,N,M");
		mlx_string_put(rt->mlx_ptr, rt->win_ptr, 10, 125, 0xFFFFFF,
			"Orient Object : I,J,K,L,U,O");
	}
	else
		mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->cam->img.ptr,
			0, 0);
}

void	redraw_window(t_mini_rt *rt)
{
	setup_rt(rt);
	multi_thread(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->cam->img.ptr, 0, 0);
	show_keybind(rt);
}

t_element	*element_cpy(t_element *elem, t_mini_rt *rt)
{
	t_element	*new_elem;

	new_elem = ft_calloc(1, sizeof(t_element));
	if (!new_elem)
		handle_error("fail to malloc", rt);
	ft_memcpy(new_elem, elem, sizeof(t_element));
	return (new_elem);
}
