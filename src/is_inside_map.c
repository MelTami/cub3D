/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:46 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:47 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function checks if a given point (x, y) is inside the map boundaries.
 *
 * @param data A pointer to a struct called "t_data" which contains information
 * about the map, such as its width and height.
 * @param x The x-coordinate of the point to check if it is inside the map.
 * @param y The "y" parameter represents the y-coordinate of a point.
 *
 * @return a boolean value indicating whether the given coordinates (x, y) are
 * inside the map or not.
 */
int	is_inside_map(t_data *data, float x, float y)
{
	return (
		x >= 0
		&& x <= data->width * TILE_SIZE
		&& y >= 0
		&& y <= data->height * TILE_SIZE
	);
}
