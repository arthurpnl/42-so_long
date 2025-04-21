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
	bt_map(path, game, game->start_x, game->start_y);
	if (path->collectible_found == game->collectible_count && path->exit_found == 1)
		return (free_pathfinder(path, game->line_count), SUCCESS);
    else
        return (ft_printf("Error : Collectible/Exit not reachable"), free_pathfinder(path, game->line_count), FAILURE);
}
/*
void	bt_map(t_pathfinder *path, t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= game->len_line || y >= game->line_count)
	    return ;
	if (game->map[y][x] == '1' || path->visited[y][x] == '1')
		return ;
	if (game->map[y][x] == 'P')
		path->visited[y][x] = '1';
	if (game->map[y][x] == '0')
		path->visited[y][x] = '1';
	if (game->map[y][x] == 'C')
	{
		path->collectible_found++;
        path->visited[y][x] = '1';
	}
	if (game->map[y][x] == 'E')
    {
        path->exit_found = 1;
        path->visited[y][x] = '1';
    }

    bt_map(path, game, x, y - 1);  // haut
    bt_map(path, game, x, y + 1);  // bas
    bt_map(path, game, x - 1, y);  // gauche
    bt_map(path, game, x + 1, y);  // droite
}
*/

void	bt_map(t_pathfinder *path, t_game *game, int x, int y)
{
	// Vérifie si l'on dépasse les limites ou si on est déjà passé par là
	if (x <= 0 || y <= 0 || x >= game->len_line || y >= game->line_count)
		return ;
	if (game->map[y][x] == '1' || path->visited[y][x] == '1')
		return ;

	// Marquer la case comme visitée
	path->visited[y][x] = '1';

	// Détecte un collectible
	if (game->map[y][x] == 'C')
	{
		path->collectible_found++;
		ft_printf("[DEBUG] Collectible trouvé par pathfinding à (%d, %d)\n", y, x);
	}

	// Détecte un exit
	if (game->map[y][x] == 'E')
	{
		path->exit_found = 1;
		ft_printf("[DEBUG] Exit trouvé par pathfinding à (%d, %d)\n", y, x);
	}

	// Appelle récursivement toutes les directions
	bt_map(path, game, x, y - 1);  // haut
	bt_map(path, game, x, y + 1);  // bas
	bt_map(path, game, x - 1, y);  // gauche
	bt_map(path, game, x + 1, y);  // droite
}