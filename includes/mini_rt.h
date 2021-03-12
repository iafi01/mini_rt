//PUNTO, VETTORE,

#ifndef MINI_RT
# define MINI_RT

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "elements.h"

int		create_trgb(int t, int r, int g, int b);
void    my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);
int     create_color(float r, float g, float b);
float   create_sphere(t_global *a, t_sphere sph, t_ray r);

//vectors
t_vector create_vector(float x, float y, float z);
t_vector ver_sum(t_vector v1, t_vector v2);
t_vector vec_sub(t_vector v1, t_vector v2);
t_vector vec_per(t_vector v1, t_vector v2);
t_vector vec_div(t_vector v1, t_vector v2);
t_vector ver_sum_float(t_vector v1, float v2);
t_vector ver_sub_float(t_vector v1, float v2);
t_vector ver_per_float(t_vector v1, float v2);
t_vector ver_div_float(t_vector v1, float v2);
float vec_dot(t_vector v1, t_vector v2);
float vec_sqrt(t_vector v);
t_vector    vec_cross(t_vector v1, t_vector v2);
void setup_window(t_global *a, t_viewport *vp, t_imgdata *img);
void setup_viewport(t_viewport *vp);
void    main_print(t_global *a, t_viewport *vp, t_imgdata *img);


#endif