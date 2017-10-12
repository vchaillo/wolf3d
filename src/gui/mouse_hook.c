#include "wolf3d.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	update_image(e);
	return (0);
}
