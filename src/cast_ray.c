#include "../inc/cub3D.h"

static void	init_horz_ray(t_data *data, t_raycast *horz, float ray_angle);
static void	cast_horz_ray(t_data *data, t_raycast *horz, float ray_angle);
static void	init_vert_ray(t_data *data, t_raycast *vert, float ray_angle);
static void	cast_vert_ray(t_data *data, t_raycast *vert, float ray_angle);

/**
 * The function `cast_ray` determines whether a vertical or horizontal ray hits a
 * wall first and updates the corresponding ray data.
 *
 * @param data A pointer to a data structure that contains information about the
 * game world and the rays being cast.
 * @param ray_angle The angle at which the ray is cast. It represents the direction
 * in which the ray is traveling.
 * @param strip_id The strip_id parameter represents the index of the ray in the
 * data->rays array. It is used to store the information about the ray's properties
 * such as distance, wall hit coordinates, wall texture, and whether it was hit
 * vertically or horizontally.
 */
void	cast_ray(t_data *data, float ray_angle, int strip_id)
{
	t_raycast	vert;
	t_raycast	horz;

	data->rays[strip_id].angle = ray_angle;
	cast_horz_ray(data, &horz, ray_angle);
	cast_vert_ray(data, &vert, ray_angle);
	if (vert.distance < horz.distance)
	{
		data->rays[strip_id].distance = vert.distance;
		data->rays[strip_id].wall_hit_x = vert.wall_hit_x;
		data->rays[strip_id].wall_hit_y = vert.wall_hit_y;
		data->rays[strip_id].wall_texture = vert.wall_texture;
		data->rays[strip_id].was_hit_vertical = 1;
	}
	else
	{
		data->rays[strip_id].distance = horz.distance;
		data->rays[strip_id].wall_hit_x = horz.wall_hit_x;
		data->rays[strip_id].wall_hit_y = horz.wall_hit_y;
		data->rays[strip_id].wall_texture = horz.wall_texture;
		data->rays[strip_id].was_hit_vertical = 0;
	}
}

/**
 * The function initializes the horizontal ray for raycasting in a game.
 *
 * @param data A pointer to a struct that contains game data, including the
 * player's position.
 * @param horz The parameter `horz` is a pointer to a `t_raycast` struct. This
 * struct contains various properties related to the horizontal raycast, such as
 * the distance to the wall, the coordinates of the wall hit, the wall texture, and
 * the intercept points.
 * @param ray_angle The ray_angle parameter represents the angle at which the ray
 * is being cast. It is used to determine the direction in which the ray is facing.
 */
static void	init_horz_ray(t_data *data, t_raycast *horz, float ray_angle)
{
	horz->distance = 3.40282347e+38F;
	horz->wall_hit_x = 0;
	horz->wall_hit_y = 0;
	horz->wall_texture = 0;
	horz->y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		horz->y_intercept += TILE_SIZE;
	horz->x_intercept = (data->player.x
			+ (horz->y_intercept - data->player.y) / tan(ray_angle));
	horz->y_step = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		horz->y_step = -horz->y_step;
	horz->x_step = TILE_SIZE / tan(ray_angle);
	if ((is_ray_facing_left(ray_angle) && horz->x_step > 0)
		|| (is_ray_facing_right(ray_angle) && horz->x_step < 0))
		horz->x_step = -horz->x_step;
	horz->next_touch_x = horz->x_intercept;
	horz->next_touch_y = horz->y_intercept;
}

/**
 * The function `cast_horz_ray` calculates the horizontal ray intersection with
 * walls in a 2D map for a given ray angle.
 *
 * @param data A pointer to a data structure that contains information about the
 * game world and the player's position.
 * @param horz A structure that contains information about the horizontal raycast,
 * such as the coordinates of the wall hit, the distance to the wall, and the
 * texture of the wall.
 * @param ray_angle The ray_angle parameter represents the angle at which the ray
 * is being cast. It is used to determine the direction in which the ray is facing
 * and to calculate the coordinates of the next point to check for a wall.
 */
static void	cast_horz_ray(t_data *data, t_raycast *horz, float ray_angle)
{
	init_horz_ray(data, horz, ray_angle);
	while (is_inside_map(data, horz->next_touch_x, horz->next_touch_y))
	{
		horz->x_to_check = horz->next_touch_x;
		horz->y_to_check = horz->next_touch_y;
		if (is_ray_facing_up(ray_angle))
			horz->y_to_check -= 1;
		if (has_wall_at(data, horz->x_to_check, horz->y_to_check))
		{
			horz->wall_hit_x = horz->next_touch_x;
			horz->wall_hit_y = horz->next_touch_y;
			if (is_ray_facing_up(ray_angle))
				horz->wall_texture = T_NO;
			if (is_ray_facing_down(ray_angle))
				horz->wall_texture = T_SO;
			horz->distance = distance_between_points(data->player.x,
					data->player.y, horz->wall_hit_x, horz->wall_hit_y);
			break ;
		}
		else
		{
			horz->next_touch_x += horz->x_step;
			horz->next_touch_y += horz->y_step;
		}
	}
}

/**
 * The function initializes the variables for vertical raycasting in a 2D game.
 *
 * @param data A pointer to a struct that contains various data related to the
 * game.
 * @param vert A pointer to a t_raycast struct, which contains information about
 * the vertical ray being cast.
 * @param ray_angle The ray_angle parameter represents the angle at which the ray
 * is being cast. It is used to determine the direction of the ray and calculate
 * the intercept points with the walls in the game world.
 */
static void	init_vert_ray(t_data *data, t_raycast *vert, float ray_angle)
{
	vert->distance = 3.40282347e+38F;
	vert->wall_hit_x = 0;
	vert->wall_hit_y = 0;
	vert->wall_texture = 0;
	vert->x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		vert->x_intercept += TILE_SIZE;
	vert->y_intercept = (data->player.y
			+ (vert->x_intercept - data->player.x) * tan(ray_angle));
	vert->x_step = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		vert->x_step = -vert->x_step;
	vert->y_step = TILE_SIZE * tan(ray_angle);
	if ((is_ray_facing_up(ray_angle) && vert->y_step > 0)
		|| (is_ray_facing_down(ray_angle) && vert->y_step < 0))
		vert->y_step = -vert->y_step;
	vert->next_touch_x = vert->x_intercept;
	vert->next_touch_y = vert->y_intercept;
}

/**
 * The function `cast_vert_ray` calculates the vertical ray intersection with walls
 * in a 2D map.
 *
 * @param data A pointer to a data structure that contains information about the
 * game state.
 * @param vert A pointer to a t_raycast struct, which contains information about
 * the vertical ray being cast.
 * @param ray_angle The ray_angle parameter represents the angle at which the ray
 * is being cast. It is used to determine the direction in which the ray is cast
 * and to calculate the appropriate texture for the wall hit.
 */
static void	cast_vert_ray(t_data *data, t_raycast *vert, float ray_angle)
{
	init_vert_ray(data, vert, ray_angle);
	while (is_inside_map(data, vert->next_touch_x, vert->next_touch_y))
	{
		vert->x_to_check = vert->next_touch_x;
		if (is_ray_facing_left(ray_angle))
			vert->x_to_check -= 1;
		vert->y_to_check = vert->next_touch_y;
		if (has_wall_at(data, vert->x_to_check, vert->y_to_check))
		{
			vert->wall_hit_x = vert->next_touch_x;
			vert->wall_hit_y = vert->next_touch_y;
			if (is_ray_facing_right(ray_angle))
				vert->wall_texture = T_EA;
			if (is_ray_facing_left(ray_angle))
				vert->wall_texture = T_WE;
			vert->distance = distance_between_points(data->player.x,
					data->player.y, vert->wall_hit_x, vert->wall_hit_y);
			break ;
		}
		else
		{
			vert->next_touch_x += vert->x_step;
			vert->next_touch_y += vert->y_step;
		}
	}
}
