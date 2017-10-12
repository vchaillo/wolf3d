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

typedef struct				s_camera
{
	t_vector				pos;
	t_vector				dir;
	
}							t_camera;

typedef struct				s_player
{
	t_camera				camera;
}							t_player;

typedef struct				s_map
{
	int*					grid;
}							t_map;

typedef struct				s_level
{
	t_player				player;
	t_map					map;
}							t_level;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						size;
	int						endian;
	int						bpp;
	t_level					level;
}							t_env;

#endif
