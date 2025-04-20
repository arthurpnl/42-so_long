#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/includes/libft.h"
#include "../Libft/includes/ft_printf.h"
#include "../Libft/includes/get_next_line.h"
#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
# define SUCCESS 1
# define FAILURE 0

typedef struct s_game
{
    // Map infos
    char    **map;
    int		line_count;
    int     len_line;
    int     size_map;
    // Player and target
    int	    start_x;
    int     start_y;
    int     player_x;
    int     player_y;
    int     exit_count;
    int     collectible_count;
    int     player_count;
    // MiniLibx
    void    *mlx;
    void	*window;
	// Sprites //
	void	*sprite_player;
	void	*sprite_wall;
	void	*sprite_ground;
	void	*sprite_collectible;
	void	*sprite_exit;

} t_game;

typedef struct s_pathfinder
{
    char    **visited;
    int		collectible_found;
    bool	exit_found;
    int     i;
} t_pathfinder;

// file check //
bool	is_ber_file(char	*file);
bool	is_regular_file(char *file);

// map parse //
bool	count_line(char *file, t_game *game);
bool	allocate_map_array(t_game *game);
char	*clean_line(char *line);
bool	read_and_clean_map(int fd, t_game *game);
bool    parse_map(char *file, t_game *game);


// map checks //
bool	is_rectangular_map(t_game *game);
bool	check_horizontal_walls(t_game *game);
bool	check_vertical_walls(t_game	*game);
bool	check_collectible(t_game *game);
bool	check_exit(t_game *game);
bool	check_start_position(t_game *game);

// map path //
void	bt_map(t_pathfinder *path, t_game *game, int x, int y);
bool	validate_path(t_game *game, t_pathfinder *path);

// game init //
void	init_game(t_game *game);
bool	init_pathfinder(t_game *game, t_pathfinder *path);

// parse //
int		parser_map(t_game	*game, char	**av);
int		parser_mlx(t_game *game);

// memory cleaner //
void	free_pathfinder(t_pathfinder *path, int line_count);
void	free_game(t_game *game);

// mlx setup //
bool	init_mlx(t_game *game);
bool    create_window(t_game *game);
bool	init_sprite(t_game *game);

// render map //
bool	render_map(t_game *game);


#endif