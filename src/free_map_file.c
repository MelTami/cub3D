/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:48 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:49 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function `free_map_file` frees the memory allocated for a `t_map_file`
 * structure and its associated fields.
 *
 * @param map_file A pointer to a structure of type t_map_file.
 *
 * @return The function does not return any value. It has a void return type.
 */
void	free_map_file(t_map_file *map_file)
{
	if (map_file == NULL)
		return ;
	if (map_file->matrix)
		ft_clear_split(map_file->matrix);
	if (map_file->texture_no)
		free(map_file->texture_no);
	if (map_file->texture_so)
		free(map_file->texture_so);
	if (map_file->texture_ea)
		free(map_file->texture_ea);
	if (map_file->texture_we)
		free(map_file->texture_we);
	if (map_file->file_content)
		queue_destroy(map_file->file_content);
	free(map_file);
}
