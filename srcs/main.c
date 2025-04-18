/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:41:14 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/07 15:41:14 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2) // Vérification des arguments
	{
		ft_printf("Usage: ./so_long <filename.ber>\n");
		return (1);
	}

	init_game(&game); // Initialisation des éléments du jeu

	// Lancer le parsing complet via la fonction centralisée
	if (parser(&game, &argv[1]) == FAILURE)
	{
		ft_printf("Failed to parse map. Exiting...\n");
		return (1);
	}

	// Vérifier la validité des chemins pour collecter les éléments et atteindre la sortie
	if (validate_path(&game) == FAILURE)
	{
		ft_printf("Map path validation failed. Exiting...\n");
		return (1);
	}

	// Si tout est validé, afficher un message de succès
	ft_printf("Map successfully parsed and validated!\n");

	// Libérer les ressources de la carte s'il y a lieu
	if (game.map)
	{
		for (int i = 0; i < game.line_count; i++)
			free(game.map[i]);
		free(game.map);
	}

	return (0);
}