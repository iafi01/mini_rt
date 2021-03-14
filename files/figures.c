#include "../includes/mini_rt.h"

float create_sphere(t_sphere sph, t_ray r)
{
	t_calc s;

	s.sub = vec_sub(r.origin, sph.origin);
	//Ora calcoliamo a, b, c dalla formula e poi facciamo il discriminante
	s.a = vec_dot(r.dir, r.dir);
	s.b = 2 * vec_dot(r.dir, s.sub);
	s.c = vec_dot(s.sub, s.sub) - pow(sph.ray, 2);
	s.delta = pow(s.b, 2) - (4 * s.a * s.c);
	if(s.delta < 0) // Non ci sono state intersezioni
		return -1;
	s.delta = sqrt(s.delta);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.delta) / s.a;
	s.t2 = (-s.b + s.delta) / s.a;
	if(s.t1 >= 0 && s.t2 > s.t1) // In questo modo fa sempre riferimento a quello più vicino
		s.t2 = s.t1;
	else if(s.t2 >= 0 && s.t1 > s.t2)
		s.t1 = s.t2;
	return(s.t1);
}