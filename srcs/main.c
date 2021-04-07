/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:05:17 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/07 14:41:00 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		main(/*int argc, char **argv*/)
{
	t_mini_rt	rt;
	ft_bzero(&rt, sizeof(t_mini_rt));
	rt.mlx_ptr = mlx_init();
	ft_printf(BLUE,"Stringa");
	printf("ciao");
	/*if (!(rt.mlx_ptr))
		handle_error("i can't initialize MiniLibX", &rt);
	if (argc > 3 || argc == 1 || (argc == 3 && !ft_strequ(argv[2], "--save")))
		handle_error("wrong arguments", &rt);
	if (argc == 3 && ft_strequ(argv[2], "--save"))
		rt.save = 1;
	if (!ft_str_end(argv[1], ".rt"))
		handle_error("wrong file extension", &rt);*/
	//parse_rt_file(argv[1], &rt);
	//start_mini_rt(&rt);
	return (1);
}