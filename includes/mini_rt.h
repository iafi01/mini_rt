/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:29 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/25 18:08:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PUNTO, VETTORE,

#ifndef MINI_RT
# define MINI_RT

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "elements.h"
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
t_color		color_average(t_color color1, t_color color2);
int     check_range_color(t_color color);


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
void        error(char *str);

//PIXEL
void        main_print(t_global *a, t_imgdata *img);
void        my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);

//RAY
t_ray create_ray(t_point origin, t_vector dir);
t_point find_point(t_ray ray, float t);
int ray_color(t_ray r, t_global *a);
void create_sphere(t_global *a, t_sphere sph, t_ray ray);

//PARSE
int parse(t_global *a, char *path, int bmp);
int check_type(t_global *a, char **words);
int parse_resolution(t_global *a, char **words);
int parse_ambient(t_global *a, char **words);
int parse_camera(t_global *a, char **words);
int parse_light(t_global *a, char **words);

int parse_sphere(t_global *a, char **words);
int parse_cylinder(t_global *a, char **words);
int parse_square(t_global *a, char **words);
int parse_plane(t_global *a, char **words);
int parse_triangle(t_global *a, char **words);

#endif