/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:45:26 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/07 17:15:40 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

/*void	parse_rt_file(char *rt_file, t_mini_rt *rt)
{
	int		fd;

	if ((fd = open(rt_file, O_RDONLY)) < 0)
		handle_error("fail to open scene file", rt);
	while (get_next_line(fd, &rt->line) > 0)
	{
		rt->split = ft_ssplit(rt->line, " \t\v\n\r\f");
		if (rt->split[0])
			check_id(rt);
		rt->split = free_split(rt->split);
		ft_strdel(&rt->line);
	}
	close(fd);
	rt->obj_count = objs_count(rt->objs_list);
	if (!(rt->cam_count = ft_lstsize(rt->cam_list)))
		handle_error("no camera available", rt);
	if (!rt->res.parsed)
		handle_error("no resolution", rt);
}*/