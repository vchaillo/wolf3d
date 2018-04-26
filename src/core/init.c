#include "wolf3d.h"

void		init_map(t_env *e)
{
	e->level.map.height = 0;
	e->level.map.width = 0;
	while (e->file[e->level.map.height])
	{
		// Print map
		ft_putendl(e->file[e->level.map.height]);
		e->level.map.height++;
		if (e->level.map.width < ft_strlen(e->file[e->level.map.height]))
			e->level.map.width = ft_strlen(e->file[e->level.map.height]);
	}
	// Print map's height and width
	ft_putstr("\nMap height = ");
	ft_putnbr(e->level.map.height);
	ft_putstr(", map width = ");
	ft_putnbr(e->level.map.width);
	ft_putstr("\n");
}

void		init_player(t_env *e)
{
	// TODO : Init player position from the map

	e->level.player.camera.pos.x = 2;
	e->level.player.camera.pos.y = 2;
	// e->level.player.camera.pos.z = 0.5;

	e->level.player.camera.dir.x = 1;
	e->level.player.camera.dir.y = -1;
	// e->level.player.camera.dir.z = 0;
}
