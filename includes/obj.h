//PUNTO, VETTORE,

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_point
{
    int x;
    int y;
    int z;
}t_point;

typedef struct s_vector
{
    t_point start;
    t_point end;
}t_vector;

typedef struct s_color
{
    int t;
    int r;
    int g;
    int b;
}t_color;

typedef struct s_resolution
{
    int x;
    int y;
}t_resolution;

typedef struct s_ambient
{
    float range;
    t_color color;
}t_ambient;

typedef struct s_camera
{

}t_camera;

typedef struct s_light
{
    t_point origin;
    float   range;
    t_color color;
}t_light;

typedef struct s_sphere
{
    t_point origin;
    int ray;
    t_color color;
}t_sphere;

typedef struct s_plane
{
    t_point center;
    float orientaion; //-1 to 1
    t_color color;
}t_plane;

typedef struct s_square
{
    t_point center;
    float range;
    float side;
    t_color color;
}t_square;

typedef struct s_cylinder
{
    t_point center;
    float range;
    float diameter;
    float height;
    t_color color;
}t_cylinder;

typedef struct s_triangle
{
    t_point first;
    t_point second;
    t_point third;
    t_color color;
}t_triangle;