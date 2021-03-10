#include "../includes/mini_rt.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int create_color(float r, float g, float b)
{
    int ir = (int)(255 * r);
    int ig = (int)(255 * g);
	int ib = (int)(255 * b);
	int color = create_trgb(0, ir, ig, ib);
    return (color);
}