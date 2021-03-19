#include "includes/mini_rt.h"

point		create_p(float x, float y, float z)
{
	point tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

vector	create_v(float x, float y, float z)
{
	vector tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}