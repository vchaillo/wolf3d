#include "wolf3d.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	// DEBUG TO DELETE
	// ft_putendl("Mouse Clicked !");
	// ft_putendl("---------------");
	// ft_putstr("button : ");
	// ft_putnbr(button);
	// ft_putstr(" ,x : ");
	// ft_putnbr(x);
	// ft_putstr(" ,y : ");
	// ft_putnbr(y);
	// ft_putendl("\n");
	(void)button;
	(void)x;
	(void)y;
	update_image(e);
	return (0);
}
