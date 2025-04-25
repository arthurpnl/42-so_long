/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:26:08 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 17:55:31 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->line_count = 0;
	game->len_line = 0;
	game->size_map = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_count = 0;
	game->collect_count = 0;
	game->collect_found = 0;
	game->player_count = 0;
	game->move = 0;
	game->mlx = NULL;
	game->window = NULL;
}

bool	init_pathfinder(t_game *game, t_pathfinder *path)
{
	path->visited = NULL;
	path->collect_found = 0;
	path->exit_found = 0;
	path->i = 0;
	path->visited = malloc(sizeof(char *) * game->line_count);
	if (!path->visited)
		return (FAILURE);
	while (path->i < game->line_count)
	{
		path->visited[path->i] = NULL;
		path->i++;
	}
	path->i = 0;
	while (path->i < game->line_count)
	{
		path->visited[path->i] = calloc(game->len_line, sizeof(char));
		if (!path->visited[path->i])
			return (free_pathfinder(path, path->i), FAILURE);
		path->i++;
	}
	return (SUCCESS);
}

void	null_sprite(t_game *game)
{
	game->player = NULL;
	game->wall = NULL;
	game->ground = NULL;
	game->collect = NULL;
	game->exit = NULL;
}
