/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:16 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/19 14:54:40 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

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