/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:44 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:17:45 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The normalize_angle function takes a pointer to a float representing an angle
 * and normalizes it to be within the range of 0 to 2π.
 *
 * @param angle A pointer to a float variable representing an angle in radians.
 */
void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}
