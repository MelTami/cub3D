/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:16:17 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:16:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_characters(t_map_file *map_file);

/**
 * The function "load_map" checks the characters in a map file, creates a matrix
 * representation of the map, checks for empty spaces, defines the map sizes,
 * checks the map edges, checks the player position, and formats the map.
 *
 * @param map_file The parameter `map_file` is a pointer to a structure of type
 * `t_map_file`.
 */
void	load_map(t_map_file *map_file)
{
	check_characters(map_file);
	map_file->matrix = get_matrix_map(map_file->file_content);
	if (!map_file->matrix)
	{
		free_map_file(map_file);
		exit_error("Failed to create map matrix");
	}
	check_empty(map_file);
	define_map_sizes(map_file);
	check_map_edges(map_file);
	check_player(map_file);
	format_map(map_file);
}

/**
 * The function "check_characters" checks if the characters in the map file are
 * valid.
 *
 * @param map_file A pointer to a structure of type t_map_file, which contains
 * information about a map file.
 */
static void	check_characters(t_map_file *map_file)
{
	t_queue_item	*tmp;
	int				i;

	if (!map_file->file_content)
	{
		free_map_file(map_file);
		exit_error("File doesn't has content");
	}
	tmp = map_file->file_content->first;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (!is_in_set(tmp->value[i], MAP_SET))
			{
				free_map_file(map_file);
				exit_error("Invalid characters in map");
			}
			i++;
		}
		tmp = tmp->next;
	}
}
