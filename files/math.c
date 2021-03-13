#include "../includes/mini_rt.h"

//crea un vettore (punto di tre coordinate)
t_vector create_vector(float x, float y, float z)
{
    t_vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

//le quattro operazioni con i due vettori
t_vector ver_sum(t_vector v1, t_vector v2)
{
    t_vector v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    return (v);
}

t_vector vec_sub(t_vector v1, t_vector v2)
{
    t_vector v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;
    return (v);
}

t_vector vec_per(t_vector v1, t_vector v2)
{
    t_vector v;
    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;
    v.z = v1.z * v2.z;
    return (v);
}

t_vector vec_div(t_vector v1, t_vector v2)
{
    t_vector v;
    v.x = v1.x / v2.x;
    v.y = v1.y / v2.y;
    v.z = v1.z / v2.z;
    return (v);
}
//le quattro operazioni con un vettore ed un float
t_vector vec_sum_float(t_vector v1, float v2)
{
    t_vector v;
    v.x = v1.x + v2;
    v.y = v1.y + v2;
    v.z = v1.z + v2;
    return (v);
}

t_vector vec_sub_float(t_vector v1, float v2)
{
    t_vector v;
    v.x = v1.x - v2;
    v.y = v1.y - v2;
    v.z = v1.z - v2;
    return (v);
}

t_vector vec_per_float(t_vector v1, float v2)
{
    t_vector v;
    v.x = v1.x * v2;
    v.y = v1.y * v2;
    v.z = v1.z * v2;
    return (v);
}

t_vector vec_div_float(t_vector v1, float v2)
{
    t_vector v;
    v.x = v1.x / v2;
    v.y = v1.y / v2;
    v.z = v1.z / v2;
    return (v);
}

//riproduce la funzione dot
float vec_dot(t_vector v1, t_vector v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float vec_lenght_squared(t_vector v)
{
    return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float vec_lenght(t_vector v)
{
    return (sqrt(vec_lenght_squared(v)));
}

t_vector vec_normalize(t_vector v)
{
    t_vector normalized;
    float len = vec_lenght(v);

    normalized.x = v.x / len;
    normalized.y = v.y / len;
    normalized.z = v.z / len;
	return(normalized);
}

t_vector    vec_cross(t_vector v1, t_vector v2)
{
    t_vector v;

    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return(v);
}


