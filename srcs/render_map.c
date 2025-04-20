/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:46:47 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/19 15:46:47 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite_ground, x * 32, y * 32);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite_wall, x * 32, y * 32);
			else if(game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite_player, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite_collectible, x * 32, y *32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite_exit, x * 32, y * 32);
			else
				return (ft_printf("Error : Invalid caracter found on the map while tring to render the map.\n"), FAILURE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

