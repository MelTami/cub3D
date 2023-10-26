/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:50 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:51 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_texture_file(char *filename);
static int	is_xpm_file(char *filename);

/**
 * The function "check_texture" checks if the texture assignment is valid and if
 * the texture file exists.
 *
 * @param map_file A pointer to a structure of type t_map_file, which is not
 * defined in the code snippet provided.
 * @param tex The "tex" parameter is a pointer to a pointer to a character array.
 * It is used to store the texture assignment, which should consist of two
 * elements: the texture identifier and the texture file name.
 */
void	check_texture(t_map_file *map_file, char **tex)
{
	if (ft_split_len(tex) != 2)
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture assignment");
	}
	if (!is_valid_texture_file(tex[1]))
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture file");
	}
}

/**
 * The function "is_valid_texture_file" checks if a given filename is a valid
 * texture file by verifying its length, file extension, and existence.
 *
 * @param filename A pointer to a string representing the filename of a texture
 * file.
 *
 * @return a boolean value (0 or 1) indicating whether the given filename is a
 * valid texture file.
 */
static int	is_valid_texture_file(char *filename)
{
	char	*file_filename;

	file_filename = ft_strrchr(filename, '/');
	if (!file_filename)
		file_filename = filename;
	else
		file_filename++;
	return (
		ft_strlen(file_filename) >= 5
		&& is_xpm_file(filename)
		&& is_file(filename)
	);
}

/**
 * The function "is_xpm_file" checks if a given filename has a ".tex" extension.
 *
 * @param filename A string representing the name of a file.
 *
 * @return a boolean value (0 or 1) indicating whether the given filename has a
 * ".xpm" extension.
 */
static int	is_xpm_file(char *filename)
{
	char	*filetype;

	filetype = &filename[ft_strlen(filename) - 4];
	return (ft_strcmp(filetype, TEX_EXT) == 0);
}
