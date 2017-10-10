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
void			start_mlx(t_env *e);
int				expose_hook(t_env *e);
int		        mouse_hook(int button, int x, int y, t_env *e);

void			fill_pixel(t_env *e, t_color color, int x, int y);
void			update_image(t_env *e);
void            apply_color_to_image(t_env *e);
void			draw(t_env *e);

#endif
