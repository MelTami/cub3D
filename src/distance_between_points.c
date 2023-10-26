/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:17 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function calculates the distance between two points in a two-dimensional
 * space.
 *
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The parameter "y2" represents the y-coordinate of the second point.
 *
 * @return the distance between two points in a 2D plane.
 */
float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
