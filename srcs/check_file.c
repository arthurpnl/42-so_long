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

bool	is_ber_file(char	*file)
{
	int	len;

	len = 0;
	if (file == NULL)
		return (FAILURE);
	if (is_regular_file(file) == SUCCESS)
	{
		len = ft_strlen(file);
		if (len <= 4)
		{
			ft_printf("Error\nUnvalid file\n");
			return (FAILURE);
		}
		if (ft_strncmp(file + len - 4, ".ber", 4) == 0)
			return (SUCCESS);
		else
		{
			ft_printf("Error\nIncorrect extension file\n");
			return (FAILURE);
		}
	}
	else
		return (FAILURE);
}

bool	is_regular_file(char *file)
{
	int		fd;
	char	buffer[1];
	int		read_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Errror\nFile cannot be open\n"), FAILURE);
	read_result = read(fd, buffer, 1);
	close(fd);
	if (read_result < 0)
		return (ft_printf("Error\nNot a regular file\n"), FAILURE);
	return (SUCCESS);
}
