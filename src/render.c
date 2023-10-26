/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:53 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:17:54 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	draw_ceil(t_data *data, t_wall *wall, int x);
static void	draw_wall(t_data *data, t_wall *wall, int x);
static void	draw_floor(t_data *data, t_wall *wall, int x);
static void	render_wall_projection(t_data *data);

/**
 * The render function displays the rendered image on the window using the
 * mlx_put_image_to_window function.
 *
 * @param data A pointer to a structure that contains various data needed for
 * rendering, such as the window, canvas, and other variables.
 */
void	render(t_data *data)
{
	render_wall_projection(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->canvas->buffer, 0, 0);
}

/**
 * The function "render_wall_projection" calculates the height and position of a
 * wall in a 3D projection and then draws the ceiling, wall, and floor.
 *
 * @param data A pointer to a struct that contains various data related to the
 * game, such as the player's position and rotation, the distance to the
 * projection plane, and an array of rays that represent the player's field
 * of view.
 */
static void	render_wall_projection(t_data *data)
{
	int		x;
	t_wall	wall;

	x = 0;
	while (x < NUM_RAYS)
	{
		wall.perp_distance = (data->rays[x].distance
				* cos(data->rays[x].angle - data->player.rotation_angle));
		wall.height = (TILE_SIZE / wall.perp_distance) * data->dist_proj_plane;
		wall.top_y = (WINDOW_HEIGHT / 2) - (wall.height / 2);
		if (wall.top_y < 0)
			wall.top_y = 0;
		if (wall.top_y >= WINDOW_HEIGHT)
			wall.top_y = WINDOW_HEIGHT;
		wall.bottom_y = (WINDOW_HEIGHT / 2) + (wall.height / 2);
		if (wall.bottom_y < 0)
			wall.bottom_y = 0;
		if (wall.bottom_y > WINDOW_HEIGHT)
			wall.bottom_y = WINDOW_HEIGHT;
		draw_ceil(data, &wall, x);
		draw_wall(data, &wall, x);
		draw_floor(data, &wall, x);
		x++;
	}
}

/**
 * The function "draw_ceil" is responsible for drawing the ceiling of a wall on a
 * canvas.
 *
 * @param data A pointer to a structure of type t_data, which contains
 * information about the canvas and the colors to be used for drawing.
 * @param wall The `wall` parameter is a pointer to a `t_wall` struct.
 * @param x The parameter "x" represents the x-coordinate of the current pixel
 * being drawn on the canvas.
 */
static void	draw_ceil(t_data *data, t_wall *wall, int x)
{
	int	y;

	y = 0;
	while (y < wall->top_y)
	{
		draw_pixel(data->canvas, x, y, data->ceil_color);
		y++;
	}
}

/**
 * The function `draw_wall` is responsible for drawing a wall on the canvas based
 * on the given data and wall parameters.
 *
 * @param data A pointer to a struct that contains various data needed for
 * drawing the wall, such as the rays and textures.
 * @param wall A structure that contains information about the wall being drawn,
 * such as its top and bottom y-coordinates, height, and texture.
 * @param x The parameter `x` represents the x-coordinate of the column of pixels
 * being drawn on the canvas.
 */
static void	draw_wall(t_data *data, t_wall *wall, int x)
{
	int	y;

	if (data->rays[x].was_hit_vertical)
		wall->texture_offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
	else
		wall->texture_offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
	if (data->rays[x].was_hit_vertical
		&& is_ray_facing_left(data->rays[x].angle))
		wall->texture_offset_x = TILE_SIZE - wall->texture_offset_x;
	if (!data->rays[x].was_hit_vertical
		&& is_ray_facing_down(data->rays[x].angle))
		wall->texture_offset_x = TILE_SIZE - wall->texture_offset_x;
	wall->texture = data->textures[data->rays[x].wall_texture];
	y = wall->top_y;
	while (y < wall->bottom_y)
	{
		wall->distance_from_top = y + (wall->height / 2) - (WINDOW_HEIGHT / 2);
		wall->texture_offset_y = (wall->distance_from_top
				* ((float)wall->texture->height / wall->height));
		wall->pixel_color = get_pixel(wall->texture, wall->texture_offset_x,
				wall->texture_offset_y);
		draw_pixel(data->canvas, x, y, wall->pixel_color);
		y++;
	}
}

/**
 * The function "draw_floor" is used to draw the floor of a wall on a canvas.
 *
 * @param data A pointer to a struct called "t_data" which contains various data
 * related to the program.
 * @param wall The parameter "wall" is a pointer to a structure of type "t_wall".
 * @param x The x-coordinate of the current column of pixels being drawn on the
 * canvas.
 */
static void	draw_floor(t_data *data, t_wall *wall, int x)
{
	int	y;

	y = wall->bottom_y;
	while (y < WINDOW_HEIGHT)
	{
		draw_pixel(data->canvas, x, y, data->floor_color);
		y++;
	}
}
