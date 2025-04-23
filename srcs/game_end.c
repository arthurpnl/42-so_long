/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:31:29 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/23 11:41:50 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	if (!game)
		return (0);
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_exit_condition(t_game *game)
{
	if (game->collect_found == game->collect_count
		&& game->map[game->player_y][game->player_x] == 'E')
	{
		ft_printf("You finished the game in %i moves.\n", game->move);
		close_window(game);
	}
	else if (game->collect_found != game->collect_count
		&& game->map[game->player_y][game->player_x] == 'E')
		ft_printf("Error\nYou need to collect all the collectibles\n");
}
