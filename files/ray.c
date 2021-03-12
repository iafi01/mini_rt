#include "mini_rt.h"

t_ray create_ray(t_vector origin, t_vector dir)
{
    t_ray ray;
    ray.origin = origin;
    ray.dir = dir;
    return (ray);
}

// la formula matematica  Pt = A + tB (retta)
t_vector find_point(t_ray ray, float t)
{
    return (vec_add(vec_per_float(ray.dir, t)), ray.origin);
}

t_vector ray_color(t_ray r, t_global *a)
{
    t_sphere sph;
    t_triangle tr;
    t_plane pl;
    t_vector norm;

    sph.origin = create_vector(0.0,0.0,-1.7);
    sph.ray = 0.7;

    tr.p1 = create_vector(-1.0,-1.0,-2.0);
    tr.p2 = create_vector(-1.5,-1.5,-2.0);
    tr.p3 = create_vector(-2.0,-2.0,-2.0);

    pl.center = create_vector(-0.5,-0.5,-1.0);
    pl.orientation = create_vector(-1.5,-1.5,-1.5);

    a->t = create_sphere(a, sph, r);
    if (a->t > 0)
    {
        //controlla l'intersezione raggio sfera
    }

    a->color = create_color(1.0,1.0,1.0);
    a->color2 = create_color(0.5,0.7,1.0);
}