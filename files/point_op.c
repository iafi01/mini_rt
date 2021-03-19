#include "../includes/mini_rt.h"

// Somma tra un punto e un vettore

t_point			sum_p_vec(t_point p, t_vector v)
{
	return(create_p(p.x + v.x, p.y + v.y, p.z + v.z));
}

// Differenza tra un punto e un vettore

t_point			diff_p_vec(t_point p, t_vector v)
{
	return(create_p(p.x - v.x, p.y - v.y, p.z - v.z));
}

// Moltiplicazione di un punto per uno scalare

t_point			mult_t_point_scal(t_point p, float a)
{
	return(create_p(p.x * a, p.y * a, p.z * a));
}

// Negare un punto

t_point			neg_point(t_point p)
{
	return(mult_t_point_scal(p, (-1.0)));
}