/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:16:13 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:16:14 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	key_pressed(int key_code, t_data *data);
static int	key_released(int key_code, t_data *data);

/**
 * The key_hook function sets up event hooks for key presses, key releases, and
 * window close events.
 *
 * @param data The parameter "data" is a pointer to a structure of type "t_data".
 * This structure likely contains information about the window and other data
 * related to the program.
 */
void	key_hook(t_data *data)
{
	mlx_hook(data->window, 2, 1, &key_pressed, data);
	mlx_hook(data->window, 3, 10, &key_released, data);
	mlx_hook(data->window, 17, 0L, &free_data, data);
}

/**
 * The function "key_pressed" updates the player's movement direction based on
 * the key code received.
 *
 * @param key_code The key code parameter represents the code of the key that was
 * pressed on the keyboard. It is an integer value that corresponds to a specific
 * key on the keyboard.
 * @param data The parameter "data" is a pointer to a structure of type "t_data".
 * This structure likely contains various data related to the game or program
 * that this function is a part of. The function is using this parameter to
 * access and modify the "player" field within the "data" structure.
 *
 * @return an integer value of 0.
 */
static int	key_pressed(int key_code, t_data *data)
{
	if (key_code == EXIT)
		free_data(data);
	if (key_code == LOOK_RIGHT)
		data->player.turn_direction = +1;
	if (key_code == LOOK_LEFT)
		data->player.turn_direction = -1;
	if (key_code == RIGHT)
		data->player.strafe_direction = +1;
	if (key_code == LEFT)
		data->player.strafe_direction = -1;
	if (key_code == UP)
		data->player.walk_direction = +1;
	if (key_code == DOWN)
		data->player.walk_direction = -1;
	return (0);
}

/**
 * The function key_released updates the player's movement direction based on the
 * released key code.
 *
 * @param key_code The key code is an integer value that represents the key that
 * was released. It is used to determine which action should be taken based on
 * the released key.
 * @param data The parameter `data` is a pointer to a `t_data` struct.
 *
 * @return an integer value of 0.
 */
static int	key_released(int key_code, t_data *data)
{
	if (key_code == LOOK_RIGHT)
		data->player.turn_direction = 0;
	if (key_code == LOOK_LEFT)
		data->player.turn_direction = 0;
	if (key_code == RIGHT)
		data->player.strafe_direction = 0;
	if (key_code == LEFT)
		data->player.strafe_direction = 0;
	if (key_code == UP)
		data->player.walk_direction = 0;
	if (key_code == DOWN)
		data->player.walk_direction = 0;
	return (0);
}
