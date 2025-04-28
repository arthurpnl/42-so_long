/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:06:31 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/28 11:17:19 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	select_move(int keycode, t_game *game)
{
	if (keycode == 119)
		move_up(game);
	else if (keycode == 115)
		move_down(game);
	else if (keycode == 97)
		move_left(game);
	else if (keycode == 100)
		move_right(game);
}

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("ESC pressed.\n");
		destroy_free_mlx(game);
	}
	select_move(keycode, game);
	return (0);
}
