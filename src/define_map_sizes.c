/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:08 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:09 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_map_width(char **map);
static int	get_map_height(char **map);

/**
 * The function `define_map_sizes` calculates the width and height of a map and
 * checks for any errors.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 */
void	define_map_sizes(t_map_file *map_file)
{
	char	*err_msg;

	err_msg = NULL;
	map_file->width = get_map_width(map_file->matrix);
	map_file->height = get_map_height(map_file->matrix);
	if (map_file->width == 0 && map_file->height == 0)
		err_msg = "Map doesn't has width and height";
	else if (map_file->width == 0)
		err_msg = "Map doens't has width";
	else if (map_file->height == 0)
		err_msg = "Map doesn't has height";
	if (err_msg)
	{
		free_map_file(map_file);
		exit_error(err_msg);
	}
}

/**
 * The function "get_map_width" calculates the width of a map by counting the
 * number of characters in the first row.
 *
 * @param map A pointer to a pointer to a character array, representing a map.
 *
 * @return the width of the map.
 */
static int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width])
		width++;
	return (width);
}

/**
 * The function "get_map_height" calculates the height of a map by counting the
 * number of rows in a 2D array.
 *
 * @param map The parameter `map` is a pointer to a pointer to a character. It
 * represents a 2D array of characters, where each element is a string. The end
 * of the array is marked by a NULL pointer.
 *
 * @return the height of the map, which is an integer value.
 */
static int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
