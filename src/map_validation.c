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

bool	is_rectangular_map(t_data *game)
{
	int	i;
	int    len;

	i = 0;
	game->len_line = ft_strlen(game->map[0]);
	while(i < game->line_count)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->len_line)
		{
			write(2, "Error\nUnvalid Map\n", 18);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

bool	check_horizontal_walls(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->len_line)
	{
		if (game->map[0][i] == '1')
			i++;
		else
			return (write(2, "Error\nInvalid Map\n", 18), FAILURE);
	}
	while (j < game->len_line)
	{
		if (game->map[game->line_count - 1][j] == '1')
			i++;
		else
			return (write(2, "Error\nInvalid Map\n", 18), FAILURE);
	}
	return (SUCCESS);
}

bool	check_vertical_walls(t_data	*game)
{
	int	i;
	int	j;

	i = 0;
}





