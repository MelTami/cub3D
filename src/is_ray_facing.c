/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_facing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:50 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:51 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function determines if a ray is facing downwards based on the given angle.
 *
 * @param angle The angle parameter is a float value representing the angle in
 * radians.
 *
 * @return a boolean value indicating whether the given angle is facing
 * downwards.
 */
int	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * The function checks if a ray is facing up based on the given angle.
 *
 * @param angle The angle parameter is a float value representing the angle at
 * which a ray is facing.
 *
 * @return the opposite of the result of the function is_ray_facing_down.
 */
int	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

/**
 * The function determines if a ray is facing to the right based on the given
 * angle.
 *
 * @param angle The angle parameter represents the angle at which a ray is
 * facing.
 *
 * @return a boolean value indicating whether the ray is facing right or not.
 */
int	is_ray_facing_right(float angle)
{
	return (angle < PI * 0.5 || angle > PI * 1.5);
}

/**
 * The function is_ray_facing_left determines if a ray is facing left based on
 * the given angle.
 *
 * @param angle The angle parameter is a float value representing the direction
 * in which the ray is facing.
 *
 * @return the result of the expression "!is_ray_facing_right(angle)".
 */
int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
