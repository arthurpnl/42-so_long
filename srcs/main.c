#include "../includes/so_long.h"

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	ft_printf("Closing game...\n");
	destroy_free_mlx(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// Vérification du nombre d'arguments
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		return (EXIT_FAILURE);
	}

	// Initialisation des structures de jeu
	init_game(&game);

	// Parsing et validation de la carte
	if (parser_map(&game, &argv[1]) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);

	// Initialisation graphique avec MiniLibX
	if (parser_mlx(&game) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);

	// Rendu initial de la carte sur l'écran
	if (render_map(&game) == FAILURE)
		return (free_game(&game), EXIT_FAILURE);

	// Mise en place des hooks pour le clavier et la fermeture de la fenêtre
	mlx_hook(game.window, 17, 0, close_game, &game);                   // Fermeture de la fenêtre (croix rouge)
	mlx_hook(game.window, 2, 1L << 0, key_press_hook, &game);          // Gestion des touches pressées (mouvements)

	// Boucle principale de MiniLibX (rendu graphique)
	mlx_loop(game.mlx);

	// Tout s'est bien passé !
	return (EXIT_SUCCESS);
}