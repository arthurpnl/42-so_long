/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:19:05 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/21 23:43:44 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map[y][x];
	if (pos == '1')
		return (FAILURE);
	else if (pos == 'E')
	{
		if (game->collect_count == game->collect_found)
		{
			ft_printf("You finished the game in %i moves.\n", game->move + 1);
			destroy_free_mlx(game);
		}
		else if (game->collect_found != game->collect_count)
		{
			ft_printf("Error\nYou still need to collect items !\n");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	move_up(t_game *game)
{
	if (check_move(game, game->player_y - 1, game->player_x) == FAILURE)
		return (FAILURE);
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
		{
			game->collect_found++;
			game->map[game->player_y - 1][game->player_x] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
		render_map(game);
		check_exit_condition(game);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	move_down(t_game *game)
{
	if (check_move(game, game->player_y + 1, game->player_x) == FAILURE)
		return (FAILURE);
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			game->collect_found++;
			game->map[game->player_y + 1][game->player_x] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
		render_map(game);
		check_exit_condition(game);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	move_left(t_game *game)
{
	if (check_move(game, game->player_y, game->player_x - 1) == FAILURE)
		return (FAILURE);
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			game->collect_found++;
			game->map[game->player_y][game->player_x - 1] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
		render_map(game);
		check_exit_condition(game);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	move_right(t_game *game)
{
	if (check_move(game, game->player_y, game->player_x + 1) == FAILURE)
		return (FAILURE);
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			game->collect_found++;
			game->map[game->player_y][game->player_x + 1] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
		render_map(game);
		check_exit_condition(game);
		return (SUCCESS);
	}
	return (FAILURE);
}
