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
	if (is_regular_file(file) == SUCCESS)
	{
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
	else
		return (FAILURE);
}

int	is_regular_file(char *file)
{
	int	fd;
	char	buffer[1];
	size_t read_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
	    write(2, "File does not exists or cannot be open\n", 39);
        return (FAILURE);
	}
	read_result = read(fd, buffer, 1);
	close(fd);
	if (read_result < 0)
	{
        write(2, "Not a regular file\n", 19);
        return (FAILURE);
	}
	return (SUCCESS);
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

