/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:13:01 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:13:02 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	rgb2int(int r, int g, int b);

/**
 * The function `get_color` takes a string representing an RGB color and returns
 * the corresponding integer value.
 *
 * @param texture A string representing the texture color in RGB format. The
 * format should be "R,G,B" where R, G, and B are integers representing the red,
 * green, and blue color values respectively.
 *
 * @return an integer value, which represents the color.
 */
int	get_color(char *texture)
{
	size_t	len;
	int		color;
	char	**rgb;

	if (!texture)
		return (-1);
	rgb = ft_split(texture, ',');
	if (!rgb)
		return (-1);
	len = ft_split_len(rgb);
	if (len != 3)
	{
		ft_clear_split(rgb);
		return (-1);
	}
	color = rgb2int(
			ft_atoi(rgb[0]),
			ft_atoi(rgb[1]),
			ft_atoi(rgb[2])
			);
	ft_clear_split(rgb);
	return (color);
}

/**
 * The function "rgb2int" takes three integer values representing the red, green,
 * and blue components of a color and returns a single integer value representing
 * the combined color.
 *
 * @param r The parameter "r" represents the value of the red component in the
 * RGB color model. It should be an integer between 0 and 255, inclusive.
 * @param g The parameter "g" in the above code represents the value of the green
 * component in an RGB color.
 * @param b The parameter "b" in the above code represents the blue component
 * of an RGB color. It is an integer value ranging from 0 to 255, indicating the
 * intensity of the blue color in the RGB color model.
 *
 * @return an integer value.
 */
static int	rgb2int(int r, int g, int b)
{
	int	color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}
