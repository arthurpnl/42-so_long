/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:21:41 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/11 14:21:41 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	validate_path(t_game *game, t_pathfinder *path)
{
	game->player_y = game->start_y;
	game->player_x = game->start_x;
	bt_map(path, game, game->start_x, game->start_y);
	if (path->collect_found == game->collect_count && path->exit_found == 1)
		return (free_pathfinder(path, game->line_count), SUCCESS);
	else
	{
		ft_printf(ERR_PATH);
		return (free_pathfinder(path, game->line_count), FAILURE);
	}
}

void	bt_map(t_pathfinder *path, t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= game->len_line || y >= game->line_count)
		return ;
	if (game->map[y][x] == '1' || path->visited[y][x] == '1')
		return ;
	path->visited[y][x] = '1';
	if (game->map[y][x] == 'C')
		path->collect_found++;
	if (game->map[y][x] == 'E')
	{
		path->exit_found = 1;
		return ;
	}
	bt_map(path, game, x, y - 1);
	bt_map(path, game, x, y + 1);
	bt_map(path, game, x - 1, y);
	bt_map(path, game, x + 1, y);
}
