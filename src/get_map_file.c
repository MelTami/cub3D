/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:12 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:13 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		init_map_file(t_map_file *map_file);

/**
 * The function "get_map_file" loads a map file, initializes a map structure, and
 * returns the map structure.
 *
 * @param filename A string representing the name of the file to be loaded.
 *
 * @return a pointer to a t_map_file structure.
 */
t_map_file	*get_map_file(char *filename)
{
	t_map_file	*map_file;

	check_file(filename);
	map_file = (t_map_file *)malloc(sizeof(t_map_file));
	if (map_file == NULL)
		exit_error("Cannot allocate memory in get_map_file");
	init_map_file(map_file);
	map_file->file_content = get_file_content(filename);
	if (!map_file->file_content)
	{
		free_map_file(map_file);
		exit_error("Cannot get file content");
	}
	load_textures(map_file);
	load_map(map_file);
	return (map_file);
}

/**
 * The function initializes all the fields of a struct called "map_file" to their
 * default values.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 */
static void	init_map_file(t_map_file *map_file)
{
	map_file->matrix = NULL;
	map_file->width = -1;
	map_file->height = -1;
	map_file->texture_no = NULL;
	map_file->texture_so = NULL;
	map_file->texture_ea = NULL;
	map_file->texture_we = NULL;
	map_file->ceil_color = -1;
	map_file->floor_color = -1;
	map_file->player_direction = '?';
	map_file->player_x = -1;
	map_file->player_y = -1;
}
