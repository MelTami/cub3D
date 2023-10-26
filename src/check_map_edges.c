/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:00 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:02 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_start_point(t_map_file *map_file, t_coor *start);
static int	is_closed(
				t_map_file *map_file,
				const t_coor start,
				t_coor last,
				t_coor current
				);
static void	set_cardinals(t_coor cardinals[4], t_coor pos);
static int	is_edge(t_map_file *map_file, t_coor last, t_coor pos);

/**
 * The function checks if the edges of a map are closed.
 *
 * @param map_file A pointer to a structure of type `t_map_file` which
 * represents a map file.
 */
void	check_map_edges(t_map_file *map_file)
{
	t_coor	start;

	set_start_point(map_file, &start);
	if (!is_closed(map_file, start, start, start))
	{
		free_map_file(map_file);
		exit_error("Map edges aren't closed");
	}
}

/**
 * The function "set_start_point" finds the starting point in a map by searching
 * for a sequence of '1' characters.
 *
 * @param map_file A pointer to a structure of type `t_map_file`, which contains
 * information about a map file. This structure likely includes fields such as
 * `matrix`, `height`, and `width`.
 * @param start The parameter "start" is a pointer to a structure of type
 * "t_coor". This structure likely contains two integer fields, "x" and "y",
 * which represent the coordinates of a point in a two-dimensional matrix.
 *
 * @return nothing (void).
 */
static void	set_start_point(t_map_file *map_file, t_coor *start)
{
	char	**matrix;

	matrix = map_file->matrix;
	start->y = 0;
	while (matrix[start->y])
	{
		start->x = 0;
		while (matrix[start->y][start->x])
		{
			if (matrix[start->y][start->x] == '1'
				&& start->y + 1 < map_file->height
				&& start->x + 1 < map_file->width
				&& matrix[start->y + 1][start->x] == '1'
				&& matrix[start->y][start->x + 1] == '1')
				return ;
			start->x++;
		}
		start->y++;
	}
	free_map_file(map_file);
	exit_error("Map doesn't has walls");
}

/**
 * The function checks if a given position in a map is closed, meaning it is
 * surrounded by walls or previously visited positions.
 *
 * @param map_file A pointer to a structure representing a map file. This
 * structure likely contains information about the map, such as its dimensions
 * and the matrix representing the map itself.
 * @param start The start parameter is of type t_coor and represents the starting
 * coordinates of the current path being checked.
 * @param last The parameter "last" is of type t_coor, which represents a
 * coordinate on a map. It is used to keep track of the previous coordinate
 * visited during the recursive function call.
 * @param current The current coordinate in the map matrix that we are checking.
 *
 * @return an integer value.
 */
static int	is_closed(
	t_map_file *map_file,
	const t_coor start,
	t_coor last,
	t_coor current
)
{
	t_coor	cardinals[4];
	int		i;

	if (map_file->matrix[current.y][current.x] == '#')
		return (current.y == start.y && current.x == start.x);
	map_file->matrix[current.y][current.x] = '#';
	set_cardinals(cardinals, current);
	i = 0;
	while (i < 4)
	{
		if (is_edge(map_file, last, cardinals[i])
			&& is_closed(map_file, start, current, cardinals[i]))
			return (1);
		i++;
	}
	map_file->matrix[current.y][current.x] = '1';
	return (0);
}

/**
 * The function "set_cardinals" sets the coordinates of four cardinal directions
 * (up, left, down, right) based on a given position.
 *
 * @param cardinals An array of t_coor structures representing the cardinal
 * directions (north, west, south, east).
 * @param pos The parameter "pos" is a structure of type "t_coor" that represents
 * a position. It has two members: "y" and "x", which represent the y-coordinate
 * and x-coordinate of the position, respectively.
 */
static void	set_cardinals(t_coor cardinals[4], t_coor pos)
{
	cardinals[0].y = pos.y - 1;
	cardinals[0].x = pos.x;
	cardinals[1].y = pos.y;
	cardinals[1].x = pos.x - 1;
	cardinals[2].y = pos.y + 1;
	cardinals[2].x = pos.x;
	cardinals[3].y = pos.y;
	cardinals[3].x = pos.x + 1;
}

/**
 * The function "is_edge" checks if a given position in a matrix is an edge by
 * comparing it to the boundaries of the matrix and checking if the surrounding
 * positions are empty spaces or walls.
 *
 * @param map_file A pointer to a structure of type `t_map_file`, which contains
 * information about a map file. This structure likely includes fields such as
 * `height`, `width`, and `matrix`.
 * @param last The parameter "last" is of type t_coor, which likely represents a
 * coordinate on a map. It is used to store the previous position before checking
 * if the current position is an edge.
 * @param pos The variable "pos" represents the current position in the map.
 * It is of type "t_coor", which is a structure that contains the x and y
 * coordinates of a point on the map.
 *
 * @return an integer value.
 */
static int	is_edge(t_map_file *map_file, t_coor last, t_coor pos)
{
	if (pos.y < 0 || pos.y >= map_file->height
		|| pos.x < 0 || pos.x >= map_file->width
		|| (last.y == pos.y && last.x == pos.x))
		return (0);
	return (\
		(\
			pos.y - 1 == -1 \
			|| pos.x - 1 == -1 \
			|| map_file->matrix[pos.y + 1] == NULL \
			|| map_file->matrix[pos.y][pos.x + 1] == '\0' \
			|| map_file->matrix[pos.y - 1][pos.x] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x] == ' ' \
			|| map_file->matrix[pos.y][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y][pos.x + 1] == ' ' \
			|| map_file->matrix[pos.y - 1][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y - 1][pos.x + 1] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x + 1] == ' ' \
		) && (\
			map_file->matrix[pos.y][pos.x] == '1' \
			|| map_file->matrix[pos.y][pos.x] == '#' \
		)
	);
}
