/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:50 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/09 16:56:53 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parser(t_data	*game, char	**av)
{
	if (is_ber_file(*av) == FAILURE)
		return (FAILURE);
	if (count_line(*av, game) == FAILURE)
        return (FAILURE);
	if (parse_map(*av, game) == FAILURE)
		return (FAILURE);
	if (is_rectangular_map(game) == FAILURE)
        return (FAILURE);
    if (check_horizontal_walls(game) == FAILURE)
       	return (FAILURE);
    if (check_vertical_walls(game) == FAILURE)
    	return (FAILURE);

	return (SUCCESS);
}