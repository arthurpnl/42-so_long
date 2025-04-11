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
			ft_printf("Error\nUnvalid Map\n");
			return (FAILURE);
		}
		i++;
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
		if (game->map[0][i] == '1')
			i++;
		else
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	}
	while (j < game->len_line)
	{
		if (game->map[game->line_count - 1][j] == '1')
			i++;
		else
			return (ft_printf("Error\nInvalid Map\n"), FAILURE);
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

bool	check_collectible(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j < game->line_count - 1)
	{
		while (i < game->len_line - 1)
		{
			if (game->map[j][i] == 'C')
				game->collectible_count++;
			i++;
		}
		j++;
		i = 1;
	}
	if (game->collectible_count < 1)
		return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	return (SUCCESS);
}

bool	check_start_position(t_game *game)
{
	int	start_position_count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	start_position_count = 0;
	while (++j < game->line_count - 1)
	{
		while (++i < game->len_line - 1)
		{
			if (game->map[j][i] == 'P')
			{
				game->start_x = i;
				game->start_y = j;
				start_position_count++;
			}
		}
		i = 0;
	}
	if (start_position_count != 1)
		return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	return (SUCCESS);
}

bool	check_exit(t_game *game)
{
	int	exit_count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	exit_count = 0;
	while (++j < game->line_count - 1)
	{
		while (++i < game->len_line - 1)
		{
			if (game->map[j][i] == 'E')
				exit_count++;
		}
		i = 1;
	}
	if (exit_count != 1)
		return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	return (SUCCESS);
}
