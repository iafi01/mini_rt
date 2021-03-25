/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:16 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/25 10:57:21 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_color		color_average(t_color color1, t_color color2)
{
	t_color		color;

	color.r = color1.r * color2.r;
	color.g = color1.g * color2.g;
	color.b = color1.b * color2.b;
	return (color);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

float invert_color(float v)
{
    return ((v-1)*-1);
}

int create_color(float r, float g, float b)
{
    int ir = (int)(255 * r);
    int ig = (int)(255 * g);
	int ib = (int)(255 * b);
	int color = create_trgb(0, ir, ig, ib);
    return (color);
}