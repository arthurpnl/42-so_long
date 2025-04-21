/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:32:08 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/21 16:32:08 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
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
}*/

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
			{
				game->collectible_count++;
				ft_printf("[DEBUG] Collectible trouvé à (%d, %d)\n", j, i); // Ajout debug
			}
			i++;
		}
		j++;
		i = 1;
	}
	if (game->collectible_count < 1)
		return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	ft_printf("[DEBUG] Nombre total de collectibles : %d\n", game->collectible_count);
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
	while (j < game->line_count)
	{
		i = 0;
		while (i < game->len_line)
		{
			if (game->map[j][i] == 'E')
				exit_count++;
			i++;
		}
		j++;
	}
	if (exit_count != 1)
		return (ft_printf("Error\nInvalid Map\n"), FAILURE);
	game->exit_count = exit_count;
	return (SUCCESS);
}
