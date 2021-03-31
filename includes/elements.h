/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:57:32 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/31 11:45:25 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS
# define ELEMENTS

typedef struct s_point
{
    float x;
    float y;
    float z;
}t_point;

typedef struct s_vector
{
    float x;
    float y;
    float z;
}t_vector;

typedef struct s_color
{
    float r;
    float g;
    float b;
}t_color;

typedef struct  s_imgdata {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_imgdata;

typedef struct s_ray
{
    t_point origin;
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
    t_point position;
    t_vector direction;
    t_vector fov;
}t_camera;

typedef struct s_light
{
    t_point origin;
    float   range;
    t_color color;
}t_light;

typedef struct s_sphere
{
    t_point origin;
    float diameter;
    t_color color;
}t_sphere;

typedef struct s_plane
{
    t_point center;
    t_vector orientation; //-1 to 1
    t_color color;
}t_plane;

typedef struct s_square
{
    t_point center;
    float range;
    float side;
    t_color color;
}t_square;

typedef struct s_cylinder
{
    t_point center;
    float range;
    float diameter;
    float height;
    t_color color;
}t_cylinder;

typedef struct s_triangle
{
    t_point p1;
    t_point p2;
    t_point p3;
    t_color color;
}t_triangle;

//MLX_RESOURCES/VIEWPORT/COLORS/PARSING/RESOLUTION/AMBIENT/CAMERA/LIGHT

typedef struct s_global{
    void       *mlx;
    void       *mlx_win;
    float       aspect_ratio;
    t_calc      s;
    t_point     lower_left_corner;
    t_vector    hor_axis;
    t_vector    ver_axis;
    t_point     origin;

    t_color    color1;
    t_color    color2;
    float      t;
    t_point    point;

    char       *line;
    char       **split;
    int        fd;
    
    int        width;
    int        height;

    float      range;
    t_color    color;
    t_list     *lista;

    t_light    *light;
    t_camera   *camera;
    t_plane    *pl;
    t_sphere   *sph;
    t_cylinder *cy;
    t_triangle *tr;
    t_square   *sq;
    
    t_imgdata *img;
}t_global;

#endif