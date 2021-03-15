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
float   create_sphere(t_sphere sph, t_ray r);

//MATH
t_vector create_vector(float x, float y, float z);
t_vector vec_sum(t_vector v1, t_vector v2);
t_vector vec_sub(t_vector v1, t_vector v2);
t_vector vec_per(t_vector v1, t_vector v2);
t_vector vec_div(t_vector v1, t_vector v2);
t_vector vec_sum_float(t_vector v1, float v2);
t_vector vec_sub_float(t_vector v1, float v2);
t_vector vec_per_float(t_vector v1, float v2);
t_vector vec_div_float(t_vector v1, float v2);
float vec_dot(t_vector v1, t_vector v2);
float vec_lenght_squared(t_vector v);
float vec_lenght(t_vector v);
t_vector vec_normalize(t_vector v);
t_vector    vec_cross(t_vector v1, t_vector v2);

//SETUP
void setup_window(t_global *a, t_imgdata *img);
void setup_viewport(t_viewport *vp);

//PIXEL
void    main_print(t_global *a, t_viewport *vp, t_imgdata *img);
void    my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);

//RAY
t_ray create_ray(t_vector origin, t_vector dir);
t_vector find_point(t_ray ray, float t);
t_vector ray_color(t_ray r, t_global *a);

#endif