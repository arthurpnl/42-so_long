/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:01:51 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/10 16:01:51 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

bool	count_line(char *file, t_game *game)
{
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCouldn't open file\n");
		return (FAILURE);
	}
	buf = get_next_line(fd);
	if (!buf)
		return(ft_printf("Empy file.\n"), FAILURE);
	while (buf)
	{
		if(buf[0] != '\n' && buf[0] != '\0')
			game->line_count++;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

bool	allocate_map_array(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->line_count + 1));
	if (!game->map)
		return (ft_printf("Error : Allocation mémoire échouée pour la carte\n"), FAILURE);
	return (SUCCESS);
}

char	*clean_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (len > 1 && line[len - 2] == '\r')
		line[len - 2] = '\0';

	return (line);
}

bool	read_and_clean_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (i < game->line_count)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_printf("Error : Lecture échouée à la ligne %d\n", i), FAILURE);

		game->map[i++] = clean_line(line);
	}

	game->map[i] = NULL;
	return (SUCCESS);
}

bool	parse_map(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error : Impossible d'ouvrir le fichier\n"), FAILURE);

	if (allocate_map_array(game) == FAILURE)
		return (close(fd), FAILURE);

	if (read_and_clean_map(fd, game) == FAILURE)
		return (close(fd), FAILURE);

	close(fd);
	return (SUCCESS);
}


