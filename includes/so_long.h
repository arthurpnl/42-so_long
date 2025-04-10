#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
#include <unistd.h>
# define SUCCESS 1
# define FAILURE 0

// file check //
bool	is_ber_file(char	*file);
bool	is_regular_file(char *file);

// map check //
bool    parse_map(char *file, t_data	*game);
bool	count_line(char *file, t_data *game)


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

#endif