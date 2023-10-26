/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:13 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:14 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function `deg_to_rad` converts degrees to radians.
 *
 * @param deg The parameter "deg" is a float value representing an angle in
 * degrees.
 *
 * @return the value of deg converted from degrees to radians.
 */
float	deg_to_rad(float deg)
{
	return (deg * (PI / 180));
}
