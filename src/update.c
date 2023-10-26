/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:18:00 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:18:01 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	update_player(t_data *data);

/**
 * The update function updates the player's position and casts rays for
 * raycasting.
 *
 * @param data The parameter "data" is a pointer to a structure of type "t_data".
 */
void	update(t_data *data)
{
	update_player(data);
	cast_all_rays(data);
}

/**
 * The function updates the player's position based on their movement and checks
 * for collisions with walls.
 *
 * @param data A pointer to a struct that contains game data, including the
 * player's position and movement parameters.
 */
static void	update_player(t_data *data)
{
	float		move_step;
	float		strafe_step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	normalize_angle(&player->rotation_angle);
	move_step = player->walk_direction * player->walk_speed;
	strafe_step = player->strafe_direction * player->strafe_speed;
	new_player_x = player->x + cos(player->rotation_angle) * move_step;
	new_player_y = player->y + sin(player->rotation_angle) * move_step;
	new_player_x = new_player_x
		+ cos(player->rotation_angle + NINETY_RADIAN) * strafe_step;
	new_player_y = new_player_y
		+ sin(player->rotation_angle + NINETY_RADIAN) * strafe_step;
	if (!has_wall_at(data, new_player_x, new_player_y)
		&& is_inside_map(data, new_player_x, new_player_y))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}
