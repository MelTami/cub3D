/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:16:20 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:16:21 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_texture(char *content);
static void	add_all_textures(t_map_file *map_file, char *content);
static void	add_texture(t_map_file *map_file, char **tex);
static int	has_all_textures(t_map_file *map_file);

/**
 * The function "load_textures" checks if all the textures in a map file are
 * valid and adds them to the map file if they are. If any textures are missing
 * or invalid, it exits with an error message.
 *
 * @param map_file A pointer to a structure representing a map file.
 */
void	load_textures(t_map_file *map_file)
{
	t_queue	*file_content;

	file_content = map_file->file_content;
	while (file_content->len > 0)
	{
		if (has_content(file_content->first->value))
		{
			if (!is_texture(file_content->first->value))
				break ;
			add_all_textures(map_file, file_content->first->value);
		}
		queue_shift(file_content);
	}
	if (!has_all_textures(map_file))
	{
		free_map_file(map_file);
		exit_error("Invalid or missing textures");
	}
}

/**
 * The function checks if the given content represents a texture by checking if
 * the first non-space character is one of the specified characters.
 *
 * @param content The parameter "content" is a pointer to a character array
 * (string) that represents the content to be checked.
 *
 * @return a boolean value (0 or 1) indicating whether the given content is a
 * texture.
 */
static int	is_texture(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (
		content[i] == 'N'
		|| content[i] == 'S'
		|| content[i] == 'E'
		|| content[i] == 'W'
		|| content[i] == 'C'
		|| content[i] == 'F'
	);
}

/**
 * The function "add_all_textures" checks if the given texture definition is
 * valid and adds it to the map file.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 * @param content The `content` parameter is a string that contains the
 * information about the textures in the map file.
 */
static void	add_all_textures(t_map_file *map_file, char *content)
{
	char	**tex;

	tex = ft_split(content, ' ');
	if (!tex)
	{
		free_map_file(map_file);
		exit_error("Failed to split content");
	}
	if (ft_strcmp(tex[0], "NO") == 0 || ft_strcmp(tex[0], "SO") == 0
		|| ft_strcmp(tex[0], "EA") == 0 || ft_strcmp(tex[0], "WE") == 0)
		check_texture(map_file, tex);
	else if (ft_strcmp(tex[0], "C") == 0 || ft_strcmp(tex[0], "F") == 0)
		check_color(map_file, tex);
	else
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture definition");
	}
	add_texture(map_file, tex);
	ft_clear_split(tex);
}

/**
 * The function `add_texture` assigns texture paths or colors to the
 * corresponding fields in the `map_file` structure, and throws an error
 * if an invalid texture is encountered.
 *
 * @param map_file A pointer to a structure of type `t_map_file`, which contains
 * various fields related to a map file.
 * @param tex The `tex` parameter is a pointer to a char array, which represents
 * the texture information. It is expected to be in the format of `{texture_type,
 * texture_path}`.
 */
static void	add_texture(t_map_file *map_file, char **tex)
{
	if (!map_file->texture_no && ft_strcmp(tex[0], "NO") == 0)
		map_file->texture_no = ft_strdup(tex[1]);
	else if (!map_file->texture_so && ft_strcmp(tex[0], "SO") == 0)
		map_file->texture_so = ft_strdup(tex[1]);
	else if (!map_file->texture_ea && ft_strcmp(tex[0], "EA") == 0)
		map_file->texture_ea = ft_strdup(tex[1]);
	else if (!map_file->texture_we && ft_strcmp(tex[0], "WE") == 0)
		map_file->texture_we = ft_strdup(tex[1]);
	else if (map_file->ceil_color == -1 && ft_strcmp(tex[0], "C") == 0)
		map_file->ceil_color = get_color(tex[1]);
	else if (map_file->floor_color == -1 && ft_strcmp(tex[0], "F") == 0)
		map_file->floor_color = get_color(tex[1]);
	else
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture");
	}
}

/**
 * The function checks if all the required textures and colors are present in the
 * map file.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 *
 * @return a boolean value indicating whether all the required textures and
 * colors have been assigned in the given `map_file` structure.
 */
static int	has_all_textures(t_map_file *map_file)
{
	return (
		map_file->texture_no
		&& map_file->texture_so
		&& map_file->texture_ea
		&& map_file->texture_we
		&& map_file->ceil_color != -1
		&& map_file->floor_color != -1
	);
}
