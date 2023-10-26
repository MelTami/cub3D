/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:24 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:25 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function "draw_pixel" is used to set the color of a pixel in an image.
 *
 * @param img The parameter `img` is a pointer to a structure of type `t_img`. 
 * This structure likely contains information about an image, such as its size, 
 * color depth, and pixel data.
 * @param x The x parameter represents the x-coordinate of the pixel to be drawn
 * on the image.
 * @param y The parameter "y" represents the y-coordinate of the pixel in the
 * image. It determines the row in which the pixel will be drawn.
 * @param color The "color" parameter is an integer value that represents the
 * color of the pixel. It typically follows the RGBA format, where the most 
 * significant byte represents the alpha channel, followed by the red, 
 * green, and blue channels.
 */
void	draw_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = (y * img->size_line) + (x * 4);
	if (img->endian == 1)
	{
		img->addr[pixel + 0] = (color >> 24);
		img->addr[pixel + 1] = (color >> 16) & 0xFF;
		img->addr[pixel + 2] = (color >> 8) & 0xFF;
		img->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->addr[pixel + 0] = (color) & 0xFF;
		img->addr[pixel + 1] = (color >> 8) & 0xFF;
		img->addr[pixel + 2] = (color >> 16) & 0xFF;
		img->addr[pixel + 3] = (color >> 24);
	}
}
