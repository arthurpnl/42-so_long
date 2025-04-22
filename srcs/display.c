/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:46:47 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/19 15:46:47 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_rows(t_game *game, int y, int x, int *fail)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->ground \
		, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall \
		, x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player \
		, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collect \
		, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit \
		, x * 32, y * 32);
	else
		*fail = 1;
}

bool	render_map(t_game *game)
{
	int	x;
	int	y;
	int	fail;

	y = 0;
	fail = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_rows(game, y, x, &fail);
			if (fail == 1)
				return (ft_printf(WRONG_CHAR_TYPE), FAILURE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
