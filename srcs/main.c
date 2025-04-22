/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:01:14 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/22 15:01:17 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	ft_printf("Errror\nClosing game...\n");
	destroy_free_mlx(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");
		return (EXIT_FAILURE);
	}
	init_game(&game);
	if (parser_map(&game, &argv[1]) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);
	if (parser_mlx(&game) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);
	if (render_map(&game) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_hook(game.window, 2, 1L << 0, key_press_hook, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
