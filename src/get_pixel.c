/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:23 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:24 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function `get_pixel` returns the color value of a pixel at a given
 * position in an image.
 *
 * @param img A pointer to a structure of type t_img, which likely contains
 * information about an image such as its address, size line, and bits per 
 * pixel (bpp).
 * @param x The x parameter represents the x-coordinate of the pixel in the
 * image. It specifies the horizontal position of the pixel within the image.
 * @param y The parameter "y" represents the vertical coordinate of the pixel in
 * the image. It specifies the row number of the pixel in the image.
 *
 * @return the value of the pixel at the specified coordinates (x, y) in the
 * image.
 */
int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + ((y * img->size_line) + (x * img->bpp / 8));
	return (*(unsigned int *)dst);
}
