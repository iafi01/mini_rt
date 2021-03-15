/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:32 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/15 16:57:45 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS
# define ELEMENTS


//questo é un punto, un vettore é formato
// da due punti (scelta convenzionale)
typedef struct s_vector
{
    int x;
    int y;
    int z;
}t_vector;

typedef struct s_global{
     void    *mlx;
     void    *mlx_win;
     int      width;
     int      height;
     t_vector        color;
     t_vector        color2;
     float       t;
     t_vector point;
}t_global;

typedef struct s_viewport
{
	t_vector lower_left_corner;
	t_vector hor_axis;
	t_vector ver_axis;
	t_vector origin;
}				t_viewport;

typedef struct  s_imgdata {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_imgdata;

typedef struct s_color
{
    int t;
    int r;
    int g;
    int b;
}t_color;

typedef struct s_ray
{
    t_vector origin;
    t_vector dir;
}t_ray;

typedef struct s_calc
{
	float a;
	float b;
	float c;
	float delta;
	float t1;
	float t2;
	t_vector sub;
}t_calc;

typedef struct s_resolution
{
    int x;
    int y;
}t_resolution;

typedef struct s_ambient
{
    float range;
    t_color color;
}t_ambient;

typedef struct s_camera
{
    t_vector position;
    int fov;
}t_camera;

typedef struct s_light
{
    t_vector origin;
    float   range;
    t_color color;
}t_light;

typedef struct s_sphere
{
    t_vector origin;
    float ray;
    t_vector color;
}t_sphere;

typedef struct s_plane
{
    t_vector center;
    t_vector orientation; //-1 to 1
    t_color color;
}t_plane;

typedef struct s_square
{
    t_vector center;
    float range;
    float side;
    t_color color;
}t_square;

typedef struct s_cylinder
{
    t_vector center;
    float range;
    float diameter;
    float height;
    t_color color;
}t_cylinder;

typedef struct s_triangle
{
    t_vector p1;
    t_vector p2;
    t_vector p3;
    t_color color;
}t_triangle;

#endif