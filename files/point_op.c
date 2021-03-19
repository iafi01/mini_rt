#include "../includes/mini_rt.h"

// Somma tra un punto e un vettore

point			sum_p_vec(point p, vector v)
{
	return(create_p(p.x + v.x, p.y + v.y, p.z + v.z));
}

// Differenza tra un punto e un vettore

point			diff_p_vec(point p, vector v)
{
	return(create_p(p.x - v.x, p.y - v.y, p.z - v.z));
}

// Moltiplicazione di un punto per uno scalare

point			mult_point_scal(point p, float a)
{
	return(create_p(p.x * a, p.y * a, p.z * a));
}

// Negare un punto

point			neg_point(point p)
{
	return(mult_point_scal(p, (-1.0)));
}