/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:32 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:33 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function format_map takes a map file and replaces all characters that are
 * not '0' or ' ' with '1'.
 *
 * @param map_file A pointer to a structure of type t_map_file, which contains
 * information about a map file. The structure likely includes a 2D matrix (map)
 * represented as a char array, as well as the player's current position on the 
 * map (player_x and player_y).
 */
void	format_map(t_map_file *map_file)
{
	int	row;
	int	col;

	map_file->matrix[map_file->player_y][map_file->player_x] = '0';
	row = 0;
	while (map_file->matrix[row])
	{
		col = 0;
		while (map_file->matrix[row][col])
		{
			if (map_file->matrix[row][col] != '0'
				&& map_file->matrix[row][col] != ' ')
				map_file->matrix[row][col] = '1';
			col++;
		}
		row++;
	}
}
