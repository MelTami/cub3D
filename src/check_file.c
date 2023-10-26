/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:25 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:26 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_cub_file(char *filename);

/**
 * The function "check_file" checks if a given file is a valid .cub file 
 * and if it exists.
 *
 * @param filename A pointer to a string representing the name of a file.
 */
void	check_file(char *filename)
{
	char	*file_filename;

	file_filename = ft_strrchr(filename, '/');
	if (!file_filename)
		file_filename = filename;
	else
		file_filename++;
	if (ft_strlen(file_filename) < 5)
		exit_error("Invalid file");
	if (is_cub_file(filename) != 1)
		exit_error("Invalid file type");
	if (is_file(filename) != 1)
		exit_error("File does not exist");
}

/**
 * The function checks if a given filename has a ".cub" extension.
 *
 * @param filename A string representing the name of a file.
 *
 * @return a boolean value (0 or 1) indicating whether the given filename has a
 * ".cub" extension.
 */
static int	is_cub_file(char *filename)
{
	char	*filetype;

	filetype = &filename[ft_strlen(filename) - 4];
	return (ft_strcmp(filetype, MAP_EXT) == 0);
}

/**
 * The function checks if a file exists by attempting to open it and then closing
 * it.
 *
 * @param filename A pointer to a string representing the name of the file to
 * check.
 *
 * @return The function is_file returns an integer value. If the file specified
 * by the filename parameter exists and can be opened for reading, the function
 * returns 1. Otherwise, if the file does not exist or cannot be opened, the
 * function returns 0.
 */
int	is_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
