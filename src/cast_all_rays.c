/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:10:16 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/18 23:11:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function "cast_all_rays" casts rays in a loop for each column to calculate
 * the angle and then calls the "cast_ray" function.
 *
 * @param data The "data" parameter is a pointer to a structure of type "t_data".
 * This structure likely contains various data related to the game or simulation
 * being implemented. It could include information such as the player's position
 * and rotation angle, the distance to the projection plane, and other relevant
 * variables.
 */
void	cast_all_rays(t_data *data)
{
	int		col;
	float	ray_angle;
	float	angle_adjust;

	col = 0;
	while (col < NUM_RAYS)
	{
		angle_adjust = atan((col - (NUM_RAYS / 2)) / data->dist_proj_plane);
		ray_angle = data->player.rotation_angle + angle_adjust;
		normalize_angle(&ray_angle);
		cast_ray(data, ray_angle, col);
		col++;
	}
}
