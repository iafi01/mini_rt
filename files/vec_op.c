#include "includes/mini_rt.h"

// Somma di due vettori.

vector		sum_vec_vec(vector v1, vector v2)
{
	return(create_v(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

// Differenza tra due punti mi restituisce un vettore

vector		diff_p_p(point p1, point p2)
{
	return(create_v(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z));
}

// Differenza tra due vettori

vector		diff_vec_vec(vector v1, vector v2)
{
	return(create_v(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

// Moltiplicazione di un vettore per uno scalare

vector		mult_vec_scal(vector v, float a)
{
	return(create_v(v.x * a, v.y * a, v.z * a));
}

// Divisione di un vettore per uno scalare

vector		div_vec_scal(vector v, float a)
{
	return(create_v(v.x / a, v.y / a, v.z / a));
}

// Negazione di un vettore

vector		neg_vec(vector v)
{
	return(mult_vec_scal(v, (-1.0)));
}

// Norma di un vettore

float			magnitude_v(vector v)
{
	return(sqrt((v.x * v.x)+(v.y * v.y)+(v.z * v.z)));
}

// Normalizzare un vettore

vector		normalize_v(vector v)
{
	return(div_vec_scal(v, magnitude_v(v)));
}

// Prodotto scalare

float			dot_vec(vector v1, vector v2)
{
	return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// Prodotto vettoriale

vector		cross_vec(vector v1, vector v2)
{
	return(create_v((v1.y * v2.z - v1.z * v2.y), 
					(v1.z * v2.x - v1.x * v2.z), 
					(v1.x * v2.y - v1.y * v2.x)));
}
