#include "wolf3d.h"

// TODO : Check Memory Leaks on parsing
// TODO : Test strange maps and files error management
// TODO : Test directory as map argument

void		remove_spaces(char* str)
{
	char	*i;
	char	*j;

	i = str;
	j = str;
	while(*j)
	{
		*i = *j++;
		if (*i != ' ')
			i++;
	}
	*i = '\0';
}

void		check_valid_chars(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] < 48 || grid[i][j] > 57)
				print_error(PARSING_ERROR);
			j++;
		}
		i++;
	}
}

char		**read_file(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**grid;

	line = NULL;
	tmp = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	print_error(OPEN_ERROR);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
		remove_spaces(tmp);
		free(line);
	}
	grid = ft_strsplit(tmp, '\n');
	check_valid_chars(grid);
	free(tmp);
	return(grid);
}

void		parser(char *av, t_env *e)
{
	e->file = read_file(av);
	init_map(e);
	init_player(e);
}
