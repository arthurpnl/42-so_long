/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:50 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/28 11:45:31 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	parser_map2(t_game *game)
{
	t_pathfinder	path;

	if (check_vertical_walls(game) == FAILURE)
		return (FAILURE);
	if (check_collectible(game) == FAILURE)
		return (FAILURE);
	if (check_exit(game) == FAILURE)
		return (FAILURE);
	if (check_start_position(game) == FAILURE)
		return (FAILURE);
	if (init_pathfinder(game, &path) == FAILURE)
		return (FAILURE);
	if (validate_path(game, &path) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parser_map(t_game *game, char **av)
{
	if (is_ber_file(*av) == FAILURE)
		return (FAILURE);
	if (count_line(*av, game) == FAILURE)
		return (FAILURE);
	if (parse_map(*av, game) == FAILURE)
		return (FAILURE);
	if (is_rectangular_map(game) == FAILURE)
		return (FAILURE);
	if (check_valid_char(game) == FAILURE)
		return (FAILURE);
	if (check_horizontal_walls(game) == FAILURE)
		return (FAILURE);
	if (parser_map2(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parser_mlx(t_game *game)
{
	if (init_mlx(game) == FAILURE)
		return (FAILURE);
	if (create_window(game) == FAILURE)
		return (FAILURE);
	if (init_sprite(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
