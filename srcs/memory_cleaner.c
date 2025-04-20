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

void free_pathfinder(t_pathfinder *path, int line_count)
{
    int i;

	i = 0;
    if (path == NULL || path->visited == NULL)
        return;

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