/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:32 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/19 11:19:35 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS
# define ELEMENTS

typedef struct s_point
{
    float x;
    float y;
    float z;
}point;

typedef struct s_vector
{
    float x;
    float y;
    float z;
}vector;

typedef struct s_global{
     void    *mlx;
     void    *mlx_win;
     int      width;
     int      height;
     color        color;
     color        color2;
     float       t;
     point point;
}global;

typedef struct s_viewport
{
	point lower_left_corner;
	vector hor_axis;
	vector ver_axis;
	point origin;
}				viewport;

typedef struct  s_imgdata {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               imgdata;

typedef struct s_color
{
    int t;
    int r;
    int g;
    int b;
}color;

typedef struct s_ray
{
    point origin;
    vector dir;
}ray;

typedef struct s_calc
{
	float a;
	float b;
	float c;
	float delta;
	float t1;
	float t2;
	point sub;
}calc;

typedef struct s_resolution
{
    int x;
    int y;
}resolution;

typedef struct s_ambient
{
    float range;
    color color;
}ambient;

typedef struct s_camera
{
    point position;
    int fov;
}camera;

typedef struct s_light
{
    point origin;
    float   range;
    color color;
}light;

typedef struct s_sphere
{
    point origin;
    float ray;
    vector color;
}sphere;

typedef struct s_plane
{
    point center;
    vector orientation; //-1 to 1
    color color;
}plane;

typedef struct s_square
{
    point center;
    float range;
    float side;
    color color;
}square;

typedef struct s_cylinder
{
    point center;
    float range;
    float diameter;
    float height;
    color color;
}cylinder;

typedef struct s_triangle
{
    point p1;
    point p2;
    point p3;
    color color;
}triangle;

#endif