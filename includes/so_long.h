#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
#include <unistd.h>
# define SUCCESS 1
# define FAILURE 0

typedef struct s_data
{
    char    **map;
    int		line_count;
    int     len_line;
    int     size_map;
    int     player_x;
    int     player_y;
    int     exit_count;
    int     collectible_count;
    int     player_count;
} t_data;


// file check //
bool	is_ber_file(char	*file);
bool	is_regular_file(char *file);

// map parse //
bool    parse_map(char *file, t_data	*game);
bool	count_line(char *file, t_data *game);

// map validation //
bool	is_rectangular_map(t_data *game);
bool	check_horizontal_walls(t_data *game);
bool	check_vertical_walls(t_data	*game);


// init game //
void	init_game(t_data *game);

#endif