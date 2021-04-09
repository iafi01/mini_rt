/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:41:47 by sdunckel          #+#    #+#             */
/*   Updated: 2021/04/09 10:56:49 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	create_all_cam(t_mini_rt *rt)
{
	t_list		*tmp;
	int			count;

	count = 1;
	tmp = rt->cam_list;
	while (tmp)
	{
		rt->cam = tmp->content;
		if (!(rt->cam->img.ptr = mlx_new_image(rt->mlx_ptr, rt->res.x,
			rt->res.y)))
			handle_error("fail to create Minilibx image", rt);
		if (!(rt->cam->img.add = mlx_get_data_addr(rt->cam->img.ptr,
			&rt->cam->img.bpp, &rt->cam->img.size_line, &rt->cam->img.endian)))
			handle_error("fail to get Minilibx image data", rt);
		rt->cam_count > 1 ? printf("" BOLDGREEN ">> %d/%d"
			" camera <<\n" RESET, count, rt->cam_count) : 0;
		setup_rt(rt);
		multi_thread(rt);
		if (rt->save)
			return ;
		count++;
		tmp = tmp->next;
	}
}

void	select_cam(t_mini_rt *rt)
{
	t_list		*tmp;
	int			count;

	count = 0;
	tmp = rt->cam_list;
	while (tmp)
	{
		if (rt->cur_cam == count)
		{
			rt->cam = tmp->content;
			rt->cur_cam++;
			if (rt->cur_cam == rt->cam_count)
				rt->cur_cam = 0;
			return ;
		}
		count++;
		tmp = tmp->next;
	}
}

void	change_cam(t_mini_rt *rt)
{
	if (rt->cam_count > 1)
	{
		select_cam(rt);
		mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->cam->img.ptr,
			0, 0);
	}
}
