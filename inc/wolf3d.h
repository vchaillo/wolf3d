#ifndef WOLF3D_H
# define WOLF3D_H

/*
**      system includes
*/
# include <float.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <assert.h>

/*
**      wolf3d includes
*/
# include "libft.h"
# include "colors.h"
# include "structs.h"
# include "keycodes.h"
# include "macros.h"

/*
** 				gui functions
*/
/////////////// mlx.c
void			start_mlx(t_env *e);
int				expose_hook(t_env *e);
/////////////// init.c
void            init_map(t_env *e);
void            init_player(t_env *e);
void            init_level(t_env *e);
/////////////// mouse_hook.c
int		        mouse_hook(int button, int x, int y, t_env *e);
/////////////// key_hook.c
int		        key_hook(int keycode, t_env *e);
/////////////// draw.c
void			fill_pixel(t_env *e, t_color color, int x, int y);
void			update_image(t_env *e);
void            apply_color_to_image(t_env *e);
/////////////// compute.c
void            compute(t_env *e);
/////////////// error.c
void            print_error(int error);

#endif
