/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:27:55 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/18 18:27:55 by arpenel          ###   ########.fr       */
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

    game->window = mlx_new_window(game->window, window_width, window_height, "so_long");
}