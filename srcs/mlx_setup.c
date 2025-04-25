/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:27:55 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 18:01:11 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("Error : Failed to initialize MiniLibx"), FAILURE);
	return (SUCCESS);
}

bool	create_window(t_game *game)
{
	int	w_width;
	int	w_height;

	w_width = game->len_line * 32;
	w_height = game->line_count * 32;
	game->window = mlx_new_window(game->mlx, w_width, w_height, "so_long");
	if (!game->window)
		return (ft_printf("Error : Failed to create window"), FAILURE);
	return (SUCCESS);
}

bool	init_sprite(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	null_sprite(game);
	game->player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &w, &h);
	game->ground = mlx_xpm_file_to_image(game->mlx, "xpm/ground.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx, "xpm/collectible.xpm", &w,
			&h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &w, &h);
	if (!game->player || !game->wall || !game->ground || !game->exit
		|| !game->collect)
		return (destroy_free_mlx(game), ft_printf(ERR_LOAD_SPRITE), FAILURE);
	else
		return (SUCCESS);
}
