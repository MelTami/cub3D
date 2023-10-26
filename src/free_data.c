/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:40 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:41 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	free_textures(t_data *data);

/**
 * The function "free_data" is used to free memory allocated for a data structure
 * and exit the program.
 *
 * @param data The parameter `data` is a pointer to a structure of type `t_data`.
 *
 * @return an integer value.
 */
int	free_data(t_data *data)
{
	if (!data)
		return (0);
	if (data->grid)
		ft_clear_split(data->grid);
	if (data->mlx)
	{
		free_textures(data);
		if (data->canvas)
		{
			mlx_destroy_image(data->mlx, data->canvas->buffer);
			free(data->canvas);
		}
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(1);
}

/**
 * The function "free_textures" frees the memory allocated for textures in a
 * given data structure.
 *
 * @param data A pointer to a struct of type t_data, which contains information
 * about the textures and the mlx (MiniLibX) instance.
 */
static void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEX)
	{
		if (data->textures[i])
		{
			mlx_destroy_image(data->mlx, data->textures[i]->buffer);
			free(data->textures[i]);
		}
		i++;
	}
}
