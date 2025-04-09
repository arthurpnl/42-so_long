/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:15 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/08 13:26:41 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

int	is_ber_file(char	*file)
{
	int	len;

	len = 0;
	if (file == NULL)
		return (FAILURE);

	len = ft_strlen(file);
	if (len <= 4)
	{
		write(2, "Unvalid file\n", 13);
		return (FAILURE);
	}
	if (ft_strncmp(file + len - 4, ".ber", 4) == 0)
		return (SUCCESS);
	else
	{
		write(2, "Incorrect extension file\n", 25);
		return (FAILURE);
	}
}

int	file_exists(char	*file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "File does not exists or cannot be open\n", 39);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}