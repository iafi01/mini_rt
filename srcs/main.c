/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:05:17 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/07 17:15:25 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	create_window(t_mini_rt *rt)
{
	if (!(rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->res.x,
		rt->res.y, "miniRT")))
		handle_error("fail to create Minilibx window", rt);
	mlx_hook(rt->win_ptr, 2, 0, get_keypress, rt);
	mlx_hook(rt->win_ptr, 4, 0, mouse_press, rt);
	mlx_hook(rt->win_ptr, 5, 0, mouse_release, rt);
	mlx_hook(rt->win_ptr, 6, 0, get_mouse_pos, rt);
	mlx_hook(rt->win_ptr, 17, 0, exit_and_free, rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->cam->img.ptr, 0, 0);
	mlx_loop(rt->mlx_ptr);
}

void	start_mini_rt(t_mini_rt *rt)
{
	ft_printf(GREEN,"Rendering miniRT...");
	create_all_cam(rt);
	select_cam(rt);
	if (rt->save)
	{
		create_bmp_image(rt, BMP_FILE_NAME);
		ft_printf(GREEN, BMP_FILE_NAME " exported <<\n");
		exit_and_free(rt);
	}
	ft_printf(GREEN, "Creating window...");
	create_window(rt);
}

int		main(int argc, char **argv)
{
	t_mini_rt	rt;
	ft_bzero(&rt, sizeof(t_mini_rt));
	rt.mlx_ptr = mlx_init();
	printf(BLUE "Stringa");
	if (!(rt.mlx_ptr))
		handle_error("i can't initialize MiniLibX", &rt);
	if (argc != 2 && (argc != 3 || (ft_strncmp(argv[2], "--save", 6) != 0)))
		handle_error("wrong arguments", &rt);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0))
		rt.save = 1;
	if (ft_strncmp(argv[1], ".rt", 3) != 0)
		handle_error("wrong file extension", &rt);
	parse_rt_file(argv[1], &rt);
	start_mini_rt(&rt);
	return (1);
}