#include "wolf3d.h"

void            init_map(t_env *e)
{
    static int		grid[100] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    e->level.map.grid = grid;
}

void            init_player(t_env *e)
{
    e->level.player.camera.pos.x = 0;
    e->level.player.camera.pos.y = 0.5;
    e->level.player.camera.pos.z = 0;
}

void            init_level(t_env *e)
{
    init_map(e);
    init_player(e);
}
