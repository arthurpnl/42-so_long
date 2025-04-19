/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:27:55 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/19 01:04:58 by arpenel          ###   ########.fr       */
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

bool    create_window(t_game *game)
{
    int    window_width;
    int    window_height;

	window_width = game->len_line * 32;
	window_height = game->line_count * 32;
    game->window = mlx_new_window(game->mlx, window_width, window_height, "so_long");
	if (!game->window)
		return(ft_printf("Error : Failed to create window"), FAILURE);
	return (SUCCESS);
}

bool	init_sprite(t_game *game)
{
	int width;
	int	height;

	width = 64;
	height = 64;
	game->sprite_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
	game->sprite_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	game->sprite_ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", &width, &height);
	game->sprite_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &width, &height);
	game->sprite_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
	if (!game->sprite_player)
		return (ft_printf("Error : Failed to charge player image.\n"), FAILURE);
	else if (!game->sprite_wall)
		return (ft_printf("Error : Failed to charge wall image.\n"), FAILURE);
	else if (!game->sprite_ground)
		return (ft_printf("Error : Failed to charge ground image\n"), FAILURE);
	else if (!game->sprite_collectible)
		return (ft_printf("Error : Failed to charge collectible image\n"), FAILURE);
	else if (!game->sprite_exit)
		return (ft_printf("Errror : Failed to charge exit image\n"), FAILURE);
	else
		return (SUCCESS);
}
