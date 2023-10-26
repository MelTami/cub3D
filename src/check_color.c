/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:15 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:16 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	join_colors(char **tex);
static int	is_valid_rgb(char *rgb);

/**
 * The function "check_color" checks if a texture assignment is valid and if the
 * RGB value is valid.
 *
 * @param map_file A pointer to a structure of type t_map_file, which is likely a
 * data structure containing information about a map file.
 * @param tex The `tex` parameter is a pointer to a pointer to a character array.
 * It is used to store an array of strings, where each string represents a color
 * value.
 */
void	check_color(t_map_file *map_file, char **tex)
{
	if (ft_split_len(tex) < 2)
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture assignment");
	}
	join_colors(tex);
	if (!is_valid_rgb(tex[1]))
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid rgb");
	}
}

/**
 * The function "join_colors" concatenates all elements of the "tex" array into a
 * single string.
 *
 * @param tex A pointer to an array of strings (char pointers).
 *
 * @return The function does not have a return statement, so it does not 
 * explicitly return anything.
 */
static void	join_colors(char **tex)
{
	char	*tmp;
	char	*color;
	int		i;

	if (ft_split_len(tex) == 2)
		return ;
	i = 1;
	tmp = ft_strdup("");
	while (tex[i])
	{
		color = ft_strjoin(tmp, tex[i]);
		free(tex[i]);
		tex[i] = NULL;
		free(tmp);
		tmp = color;
		i++;
	}
	tex[1] = color;
}

/**
 * The function checks if a given string represents a valid RGB color value.
 *
 * @param rgb The parameter `rgb` is a pointer to a character array that 
 * represents an RGB color value.
 *
 * @return an integer value.
 */
static int	is_valid_rgb(char *rgb)
{
	int		i;
	size_t	len;

	len = ft_strlen(rgb);
	if (len < 5 || len > 11)
		return (0);
	if (count_char(rgb, ',') != 2)
		return (0);
	i = 0;
	while (rgb[i] && (ft_isdigit(rgb[i]) || rgb[i] == ','))
		i++;
	return (rgb[i] == '\0');
}
