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

bool	is_rectangular_map(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	game->len_line = ft_strlen(game->map[0]);
	while (i < game->line_count)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->len_line)
		{
			ft_printf("Error\nInvalid Map\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

bool	check_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->line_count)
	{
		while (i < game->len_line)
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'E'
				&& game->map[j][i] != 'P')
			{
				ft_printf("Error : Invalid character found.\n");
				return (FAILURE);
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (SUCCESS);
}

bool	check_horizontal_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->len_line)
	{
		if (game->map[0][i] != '1')
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
		i++;
	}
	while (j < game->len_line)
	{
		if (game->map[game->line_count - 1][j] != '1')
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
		j++;
	}
	return (SUCCESS);
}

bool	check_vertical_walls(t_game	*game)
{
	int	i;

	i = 0;
	while (i < game->line_count)
	{
		if (game->map[i][0] != '1')
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
		if (game->map[i][game->len_line - 1] != '1')
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
		i++;
	}
	return (SUCCESS);
}

