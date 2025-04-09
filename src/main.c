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

int	main(int	argc, char **argv)
{
	t_data	*game;
	if (argc != 2)
		return (0);
	else
		is_ber_file(argv[1]);
	parse_map(*argv[1], *game);
	return (0);
}