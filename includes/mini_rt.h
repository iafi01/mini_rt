/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:29 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/22 18:57:21 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PUNTO, VETTORE,

#ifndef MINI_RT
# define MINI_RT

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "elements.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

//COLOR
int		create_trgb(int t, int r, int g, int b);
int     create_color(float r, float g, float b);
float   invert_color(float v);

//FIGURES

//MATH VEC_POINT_BASE
t_point		    create_p(float x, float y, float z);
t_vector	    create_v(float x, float y, float z);

//MATH POINT_OP
t_point			sum_p_vec(t_point p, t_vector v);
t_point			diff_p_vec(t_point p, t_vector v);
t_point			mult_t_point_scal(t_point p, float a);
t_point			neg_point(t_point p);

// MATH VEC_OP
t_vector		sum_vec_vec(t_vector v1, t_vector v2);
t_vector		diff_p_p(t_point p1, t_point p2);
t_vector		diff_vec_vec(t_vector v1, t_vector v2);
t_vector		mult_vec_scal(t_vector v, float a);
t_vector		div_vec_scal(t_vector v, float a);
t_vector		neg_vec(t_vector v);
float			magnitude_v(t_vector v);
t_vector		normalize_v(t_vector v);
float			dot_vec(t_vector v1, t_vector v2);
t_vector		cross_vec(t_vector v1, t_vector v2);

//SETUP
void        setup_window(t_global *a, t_imgdata *img);
void        setup_viewport(t_viewport *vp);

//PIXEL
void        main_print(t_global *a, t_viewport *vp, t_imgdata *img);
void        my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);

//RAY

//PARSE
int parse(t_global *a, char *path, int bmp);
int check_type(t_global *a, char **words);
int parse_resolution(t_global *a, char **words);
int parse_ambient(t_global *a, char **words);
int parse_camera(t_global *a, char **words);
int parse_light(t_global *a, char **words);

#endif