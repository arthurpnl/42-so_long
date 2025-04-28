/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:55:06 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/28 11:45:26 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_pathfinder(t_pathfinder *path, int line_count)
{
	int	i;

	i = 0;
	if (path == NULL || path->visited == NULL)
		return ;
	while (i < line_count)
	{
		if (path->visited[i] != NULL)
		{
			free(path->visited[i]);
			path->visited[i] = NULL;
		}
		i++;
	}
	free(path->visited);
	path->visited = NULL;
}

void	free_game(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->line_count)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

int	destroy_free_mlx(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		free_game(game);
		game->map = NULL;
	}
	exit(0);
}
