#include "wolf3d.h"

int		key_hook(int keycode, t_env *e)
{
	// DEBUG TO DELETE
	// ft_putendl("Key Pressed !");
	// ft_putendl("-------------");
	// ft_putstr("keycode : ");
	// ft_putnbr(keycode);
	// ft_putendl("\n");

	if (keycode == KEY_ESCAPE || keycode == KEY_ESCAPE_MAC)
		exit(0);
	update_image(e);
	return (0);
}
