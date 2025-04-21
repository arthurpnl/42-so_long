/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:06:31 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/21 16:06:31 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	select_move(int keycode, t_game *game, int move)
{
	if (keycode == 119)
		move = move_up(game);
	else if (keycode == 115)
		move = move_down(game);
	else if (keycode == 97)
		move = move_left(game);
	else if (keycode == 100)
		move = move_right(game);
	return (move);
}

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		destroy_free_mlx(game);
	game->move = select_move(keycode, game, game->move);
	return (0);
}