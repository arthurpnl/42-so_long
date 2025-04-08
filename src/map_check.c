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

int	count_line(char *file)
{
	int	fd;
	int	count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);

	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	return (count);
}

char **parse_map(char *file)
{
	int fd;
	int i;
	char **map;
	char *line;

	i = 0;
	int line_count = count_line(file);

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}

	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;


	close(fd);
	return (map);
}


