/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:26:08 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/10 15:26:08 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_data *game)
{
	game->map = NULL;
	game->line_count = 0;
	game->len_line = 0;
	game->size_map = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_count = 0;
	game->collectible_count = 0;
	game->player_count = 0;
}