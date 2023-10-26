/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:32 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:33 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function checks if there is a wall at the given coordinates in a grid.
 *
 * @param data A pointer to a struct called "t_data". This struct likely contains
 * information about the game or level, such as the width and height of the grid,
 * as well as the grid itself.
 * @param x The x parameter represents the x-coordinate of a point in the grid.
 * @param y The parameter `y` represents the y-coordinate of a point in a grid.
 *
 * @return 1 if there is a wall at the given coordinates (x, y), and 0 otherwise.
 */
int	has_wall_at(t_data *data, int x, int y)
{
	int	grid_index_x;
	int	grid_index_y;

	if (x < 0 || x >= data->width * TILE_SIZE
		|| y < 0 || y >= data->height * TILE_SIZE)
		return (1);
	grid_index_x = floor(x / TILE_SIZE);
	grid_index_y = floor(y / TILE_SIZE);
	return (data->grid[grid_index_y][grid_index_x] == '1');
}
