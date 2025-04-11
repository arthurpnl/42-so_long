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

#include "so_long.h"

bool	allocate_visited(t_pathfinder *path, t_game *game)
{
	path->visited = malloc(sizeof(char *) * game->line_count);
	if (!path->visited)
		return (FAILURE);

	path->i = 0;
	while(path->i < game->line_count)
	{
		path->visited[path->i] = ft_calloc(sizeof(char), game->len_line);
	}
	return (SUCCESS);
}
