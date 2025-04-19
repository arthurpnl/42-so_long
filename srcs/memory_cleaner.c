/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:55:06 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/13 14:55:06 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_pathfinder(t_pathfinder *path, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(path->visited[i]);
		i++;
	}
	free(path->visited);
	path->visited = NULL;
}

void	free_game(t_game *game)
{
	int	i;

	/* Libère la carte (game->map) */
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

	/* Libère les sprites MiniLibX */
	if (game->sprite_player)
		mlx_destroy_image(game->mlx, game->sprite_player);
	if (game->sprite_wall)
		mlx_destroy_image(game->mlx, game->sprite_wall);
	if (game->sprite_ground)
		mlx_destroy_image(game->mlx, game->sprite_ground);
	if (game->sprite_collectible)
		mlx_destroy_image(game->mlx, game->sprite_collectible);
	if (game->sprite_exit)
		mlx_destroy_image(game->mlx, game->sprite_exit);

	/* Ferme la fenêtre MiniLibX */
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}