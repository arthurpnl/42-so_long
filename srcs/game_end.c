/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:31:29 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/21 20:31:35 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int close_window(t_game *game)
{
	if(!game)
		return (0);
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_exit_condition(t_game *game)
{

	if (game->collectible_found == game->collectible_count && game->map[game->player_y][game->player_x] == 'E')
	{
		ft_printf("Congratulations ! You found all the collectibles and exited the game.\n");
		close_window(game);
	}
	else if (game->collectible_found != game->collectible_count && game->map[game->player_y][game->player_x] == 'E')
		ft_printf("You need to collect all the collectibles before exiting.\n");
}