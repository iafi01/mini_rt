/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:29 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/19 11:22:08 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PUNTO, VETTORE,

#ifndef MINI_RT
# define MINI_RT

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "elements.h"


//COLOR
int		create_trgb(int t, int r, int g, int b);
int     create_color(float r, float g, float b);

//FIGURES

//MATH
point		create_p(float x, float y, float z);
vector	    create_v(float x, float y, float z);
vector		sum_vec_vec(vector v1, vector v2);
vector		diff_p_p(point p1, point p2);
vector		diff_vec_vec(vector v1, vector v2);
vector		mult_vec_scal(vector v, float a);
vector		div_vec_scal(vector v, float a);
vector		neg_vec(vector v);
float		magnitude_v(vector v);
vector		normalize_v(vector v);
float		dot_vec(vector v1, vector v2);
vector		cross_vec(vector v1, vector v2);

//SETUP
void        setup_window(global *a, imgdata *img);
void        setup_viewport(viewport *vp);

//PIXEL
void    main_print(global *a, viewport *vp, imgdata *img);
void    my_mlx_pixel_put(imgdata *data, int x, int y, int color);

//RAY


#endif