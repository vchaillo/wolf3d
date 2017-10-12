#include "wolf3d.h"

int		key_hook(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	if (keycode == KEY_ESCAPE || keycode == KEY_ESCAPE_MAC)
		exit(0);
	update_image(e);
	return (0);
}
