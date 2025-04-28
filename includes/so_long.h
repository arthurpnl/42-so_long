/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: arpenel <marvin@42.fr>                     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/22 13:56:18 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/22 13:56:26 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/includes/ft_printf.h"
# include "../Libft/includes/get_next_line.h"
# include "../Libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define FAILURE 0
# define SUCCESS 1
# define WRONG_CHAR_TYPE "Error\nInvalid caracter found on the map.\n"
# define ERR_PATH "Error\nCollectble/Exit not reachable\n"
# define ERR_LOAD_SPRITE "Error\nFailed to charge sprites.\n"

typedef struct s_game
{
	char	**map;
	int		line_count;
	int		len_line;
	int		size_map;
	int		start_x;
	int		start_y;
	int		player_x;
	int		player_y;
	int		exit_count;
	int		collect_count;
	int		collect_found;
	int		player_count;
	int		move;
	void	*mlx;
	void	*window;
	void	*player;
	void	*wall;
	void	*ground;
	void	*collect;
	void	*exit;

}	t_game;

typedef struct s_pathfinder
{
	char	**visited;
	int		collect_found;
	bool	exit_found;
	int		i;
}	t_pathfinder;

bool	is_ber_file(char *file);
bool	is_regular_file(char *file);
void	init_game(t_game *game);
bool	init_pathfinder(t_game *game, t_pathfinder *path);
void	null_sprite(t_game *game);
bool	count_line(char *file, t_game *game);
bool	allocate_map_array(t_game *game);
char	*clean_line(char *line);
bool	read_and_clean_map(int fd, t_game *game);
bool	parse_map(char *file, t_game *game);
bool	is_rectangular_map(t_game *game);
bool	check_horizontal_walls(t_game *game);
bool	check_vertical_walls(t_game *game);
bool	check_valid_char(t_game *game);
bool	check_collectible(t_game *game);
bool	check_start_position(t_game *game);
bool	check_exit(t_game *game);
void	bt_map(t_pathfinder *path, t_game *game, int x, int y);
bool	validate_path(t_game *game, t_pathfinder *path);
int		parser_map(t_game *game, char **av);
int		parser_mlx(t_game *game);
void	free_pathfinder(t_pathfinder *path, int line_count);
void	free_game(t_game *game);
int		destroy_free_mlx(t_game *game);
bool	init_mlx(t_game *game);
bool	create_window(t_game *game);
bool	init_sprite(t_game *game);
bool	render_map(t_game *game);
void	select_move(int keycode, t_game *game);
int		key_press_hook(int keycode, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		close_window(t_game *game);
void	check_exit_condition(t_game *game);

#endif
