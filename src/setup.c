/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:56 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:17:57 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		init_empty(t_data *data);
static t_img	*get_canvas(void *mlx);
static t_img	*get_texture_img(void *mlx, char *filename);
static void		init_textures(t_data *data, t_map_file *map_file);

/**
 * The function "setup" initializes various variables and structures needed for
 * the program.
 *
 * @param data A double pointer to a structure of type t_data. This is used to
 * store various data related to the program.
 * @param map_file A pointer to a structure of type t_map_file, which contains
 * information about the map file, such as the matrix representing the map, the
 * width and height of the map, and the player's starting position and direction.
 */
void	setup(t_data **data, t_map_file *map_file)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		free_map_file(map_file);
		exit_error("Failed to allocate memory to data");
	}
	init_empty(*data);
	(*data)->mlx = mlx_init();
	(*data)->window = mlx_new_window(
			(*data)->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			TITLE);
	(*data)->canvas = get_canvas((*data)->mlx);
	init_textures(*data, map_file);
	init_player(&(*data)->player, map_file->player_direction,
		map_file->player_y, map_file->player_x);
	(*data)->grid = map_file->matrix;
	map_file->matrix = NULL;
	(*data)->width = map_file->width;
	(*data)->height = map_file->height;
	free_map_file(map_file);
	(*data)->fov_angle = deg_to_rad(FOV_ANGLE_DEGREE);
	(*data)->dist_proj_plane = ((WINDOW_WIDTH / 2)
			/ tan((*data)->fov_angle / 2));
}

/**
 * The function initializes all the variables in the t_data struct to NULL.
 *
 * @param data The parameter `data` is a pointer to a structure of type `t_data`.
 * This structure likely contains various members that are used to store
 * information related to the program's data and state.
 */
static void	init_empty(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->canvas = NULL;
	data->grid = NULL;
	data->textures[T_NO] = NULL;
	data->textures[T_SO] = NULL;
	data->textures[T_EA] = NULL;
	data->textures[T_WE] = NULL;
}

/**
 * The function "get_canvas" creates and initializes a new image canvas with a
 * specified width and height.
 *
 * @param mlx The parameter "mlx" is a pointer to the mlx structure, which is
 * used for handling the connection between the program and the graphical
 * display. It is typically obtained by calling the mlx_init() function.
 *
 * @return a pointer to a t_img structure.
 */
static t_img	*get_canvas(void *mlx)
{
	t_img	*canvas;

	canvas = (t_img *)malloc(sizeof(t_img));
	if (!canvas)
		return (NULL);
	canvas->buffer = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	canvas->addr = mlx_get_data_addr(canvas->buffer, &canvas->bpp,
			&canvas->size_line, &canvas->endian);
	canvas->width = WINDOW_WIDTH;
	canvas->height = WINDOW_HEIGHT;
	return (canvas);
}

/**
 * The function "get_texture_img" returns a pointer to a texture image loaded
 * from a file.
 *
 * @param mlx The parameter "mlx" is a pointer to the mlx structure, which is
 * used for communication with the X server and managing windows and graphics
 * contexts.
 * @param filename The filename parameter is a string that represents the name
 * or path of the XPM file that contains the texture image.
 *
 * @return a pointer to a t_img structure.
 */
static t_img	*get_texture_img(void *mlx, char *filename)
{
	t_img	*texture;

	texture = (t_img *)malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->buffer = mlx_xpm_file_to_image(mlx, filename, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->buffer, &texture->bpp,
			&texture->size_line, &texture->endian);
	return (texture);
}

/**
 * The function initializes textures and colors for a given data structure and
 * map file.
 *
 * @param data A pointer to a structure of type t_data, which contains
 * information about the game data and textures.
 * @param map_file A structure that contains information about the map file,
 * including the paths to the texture images (texture_no, texture_so, texture_ea,
 * texture_we), and the colors for the ceiling (ceil_color) and floor
 * (floor_color).
 */
static void	init_textures(t_data *data, t_map_file *map_file)
{
	data->textures[T_NO] = get_texture_img(data->mlx, map_file->texture_no);
	data->textures[T_SO] = get_texture_img(data->mlx, map_file->texture_so);
	data->textures[T_EA] = get_texture_img(data->mlx, map_file->texture_ea);
	data->textures[T_WE] = get_texture_img(data->mlx, map_file->texture_we);
	data->ceil_color = map_file->ceil_color;
	data->floor_color = map_file->floor_color;
}
