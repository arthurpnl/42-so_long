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

#include "so_long.h"
#include <unistd.h>

int	is_ber_file(char	*file)
{
	int	len;

	len = 0;
	if (file == NULL)
		return (0);

	len = ft_strlen(file);
	if (len <= 4)
	{
		write(2, "Unvalid file\n", 13);
		return (0);
	}
	if (ft_strncmp(file + len - 4, ".ber", 4) == 0)
		return (1);
	else
	{
		write(2, "Incorrect extension file\n", 25);
		return (0);
	}
}

int	file_exists(char	*filename)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "File does not exists or cannot be open\n", 39);
		return (0);
	}
	close(fd);
	return (1);
}