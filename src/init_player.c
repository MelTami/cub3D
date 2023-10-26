/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:38 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:39 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static float	get_initial_rotation_angle(char direction);

/**
 * The function initializes the player's position, size, movement directions,
 * rotation angle, and movement speeds.
 *
 * @param player A pointer to a t_player struct, which represents the player in a
 * game.
 * @param dir The `dir` parameter represents the initial direction the player is
 * facing. It is a character that can have one of four values: 'N' (north), 'S'
 * (south), 'E' (east), or 'W' (west).
 * @param grid_y The grid_y parameter represents the y-coordinate of the player's
 * starting position on the grid.
 * @param grid_x The `grid_x` parameter represents the x-coordinate of the
 * player's starting position on a grid.
 */
void	init_player(t_player *player, char dir, int grid_y, int grid_x)
{
	player->x = ((grid_x - 1) * TILE_SIZE) + (TILE_SIZE / 2);
	player->y = ((grid_y - 1) * TILE_SIZE) + (TILE_SIZE / 2);
	player->width = 3;
	player->height = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->strafe_direction = 0;
	player->rotation_angle = get_initial_rotation_angle(dir);
	player->turn_speed = ONE_RADIAN * 0.5;
	player->walk_speed = 2;
	player->strafe_speed = 2;
}

/**
 * The function returns the initial rotation angle based on the given direction.
 *
 * @param direction The direction parameter is a character that represents the
 * cardinal direction (North, South, East, or West).
 *
 * @return a float value, which represents the initial rotation angle based on
 * the given direction.
 */
static float	get_initial_rotation_angle(char direction)
{
	if (direction == 'N')
		return (PI * 1.5);
	if (direction == 'S')
		return (PI * 0.5);
	if (direction == 'E')
		return (0);
	if (direction == 'W')
		return (PI);
	return (PI);
}
