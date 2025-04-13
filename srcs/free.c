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