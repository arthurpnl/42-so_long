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
		game->line_count++;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

bool	parse_map(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	//size_t len;

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
		/*len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';*/
		game->map[i++] = line;
	}
	game->map[i] = NULL;
	return (close(fd), SUCCESS);
}

