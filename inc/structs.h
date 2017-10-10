#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct				s_color
{
	float					r;
	float					g;
	float					b;
}							t_color;

typedef struct				s_vector
{
	float					x;
	float					y;
	float					z;
}							t_vector;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						size;
	int						endian;
	int						bpp;
}							t_env;

#endif
