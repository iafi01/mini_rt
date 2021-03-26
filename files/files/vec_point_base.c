#include "../includes/mini_rt.h"

t_point		create_p(float x, float y, float z)
{
	t_point tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_vector	create_v(float x, float y, float z)
{
	t_vector tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}