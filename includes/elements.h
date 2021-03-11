#ifndef ELEMENTS
# define ELEMENTS

typedef struct s_global{
     void    *mlx;
     void    *mlx_win;
     int      width;
     int      height;
     int color;
}t_global;

typedef struct s_vector
{
    int x;
    int y;
    int z;
}t_vector;

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
    int ray;
    t_color color;
}t_sphere;

typedef struct s_plane
{
    t_vector center;
    float orientaion; //-1 to 1
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
    t_vector first;
    t_vector second;
    t_vector third;
    t_color color;
}t_triangle;

#endif