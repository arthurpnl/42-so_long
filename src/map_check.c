/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:08:13 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/08 16:08:44 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

bool	count_line(char *file, t_data *game)
{
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldn't open file\n", 25);
		return (FAILURE);
	}
	buf = get_next_line(fd);
	while (buf)
	{
		game->line_count++;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

bool    parse_map(char *file, t_data *game)
{
	int        fd;
	int        i;
	char    *line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	game->map = malloc(sizeof(char *) * (game->line_count + 1));
	if (!game->map)
		return (close(fd), FAILURE);
	while (i < game->line_count)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (close(fd), FAILURE);
		game->map[i++] = line;
	}
	game->map[i] = NULL;
	return (close(fd), SUCCESS);
}


