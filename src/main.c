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

#include "so_long.h"

#include "so_long.h"

int main(int argc, char **argv)
{
	char **map;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (1);
	}

	if (!is_ber_file(argv[1]))
		return (1);

	if (!file_exists(argv[1]))
		return (1);

	map = parse_map(argv[1]);
	if (!map)
	{
		write(2, "Error parsing map\n", 18);
		return (1);
	}

	// Debug : afficher la map
	int i = 0;
	while (map[i] != NULL)
	{
		printf("Ligne %d: %s", i, map[i]);
		i++;
	}

	// N'oubliez pas de libérer la mémoire
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);

	return (0);
}

/*
int	main(int	argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
		is_ber_file(argv[1]);
	parse_map(char *file)
	return (0);
}
 */