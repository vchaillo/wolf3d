#include "wolf3d.h"

// TODO : Check Memory Leaks on parsing
// TODO : Test strange maps and files error management

void      init_map(char **file_content, t_env *e)
{
  int     i;
  char    **line;

  // TODO : Convert file_content to int** map's grid

  i = 0;
  while(file_content[i])
  {
    ft_putendl(file_content[i]);
    line = ft_strsplit(file_content[i], ' ');
    i++;
  }
  e->level.map.height = 10;
  e->level.map.width = 10;
}

void            init_player(t_env *e)
{
    // TODO : Init player position from the map
    e->level.player.camera.pos.x = 1.5;
    e->level.player.camera.pos.y = 0.5;
    e->level.player.camera.pos.z = 1.5;
}

char      **read_file(char *file)
{
  int     fd;
  char    *line;
  char    *tmp;
  char    **grid;

  line = NULL;
  tmp = NULL;
  fd = open(file, O_RDONLY);
  if (fd < 0)
    print_error(OPEN_ERROR);
  while (get_next_line(fd, &line) > 0)
  {
    tmp = ft_strjoin(tmp, line);
    tmp = ft_strjoin(tmp, "\n");
    free(line);
  }
  grid = ft_strsplit(tmp, '\n');
  free(tmp);
  return(grid);
  // while(grid[i] != )

}

void      parser(char *path, t_env *e)
{
  char    **file_content;

  file_content = read_file(path);
  init_map(file_content, e);
  init_player(e);
}
