#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
# define SUCCESS 1
# define FAILURE 0

typedef struct s_game
{
    char    **map;
    int		line_count;
    int     len_line;
    int     size_map;
    int	    start_x;
    int     start_y;
    int     player_x;
    int     player_y;
    int     exit_count;
    int     collectible_count;
    int     player_count;
} t_game;

typedef struct s_pathfinder
{
    char    **visited;
    int		collectible_found;
    bool	exit_found;
    int     i;
    int     j;
} t_pathfinder;

// file check //
bool	is_ber_file(char	*file);
bool	is_regular_file(char *file);

// map parse //
bool    parse_map(char *file, t_game *game);
bool	count_line(char *file, t_game *game);

// map validation //
bool	is_rectangular_map(t_game *game);
bool	check_horizontal_walls(t_game *game);
bool	check_vertical_walls(t_game	*game);
bool	check_collectible(t_game *game);
bool	check_exit(t_game *game);
bool	check_start_position(t_game *game);

// init game //
void	init_game(t_game *game);
void	init_game_path(t_pathfinder *path);

#endif