/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:30 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:31 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_number_of_players(char **matrix);
static void	set_player_position(t_map_file *map_file);
static int	is_player_inside_map(char **matrix, int player_y, int player_x);

/**
 * The function "check_player" checks if there is exactly one player on the
 * map and if the player is inside the map.
 *
 * @param map_file A pointer to a structure of type `t_map_file`, which contains
 * information about the map and the player.
 */
void	check_player(t_map_file *map_file)
{
	int		num_of_players;

	num_of_players = get_number_of_players(map_file->matrix);
	if (num_of_players != 1)
	{
		free_map_file(map_file);
		if (num_of_players > 0)
			exit_error("The map has more than one player");
		else
			exit_error("The map doesn't has player");
	}
	set_player_position(map_file);
	if (!is_player_inside_map(
			map_file->matrix,
			map_file->player_y,
			map_file->player_x))
	{
		free_map_file(map_file);
		exit_error("Player is not inside the map");
	}
}

/**
 * The function "get_number_of_players" counts the number of players in a matrix.
 *
 * @param matrix The parameter `matrix` is a pointer to a pointer to a character.
 * It represents a 2D array or matrix of characters. Each element in the matrix
 * represents a player in a game.
 *
 * @return the number of players found in the matrix.
 */
static int	get_number_of_players(char **matrix)
{
	int	num_of_players;
	int	row;
	int	col;

	num_of_players = 0;
	row = 0;
	while (matrix[row])
	{
		col = 0;
		while (matrix[row][col])
		{
			if (is_in_set(matrix[row][col], PLAYER_SET))
				num_of_players++;
			col++;
		}
		row++;
	}
	return (num_of_players);
}

/**
 * The function sets the position of the player in a map file.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 */
static void	set_player_position(t_map_file *map_file)
{
	int		y;
	int		x;
	char	**matrix;

	matrix = map_file->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x]
			&& !is_in_set(matrix[y][x], PLAYER_SET))
			x++;
		if (is_in_set(matrix[y][x], PLAYER_SET))
			break ;
		y++;
	}
	if (matrix[y] == NULL
		|| matrix[y][x] == '\0')
	{
		free_map_file(map_file);
		exit_error("Map doesn't has a player");
	}
	map_file->player_direction = matrix[y][x];
	map_file->player_x = x;
	map_file->player_y = y;
}

/**
 * The function checks if the player is inside the map by checking if the
 * surrounding cells are walls.
 *
 * @param matrix A 2D array representing the game map. Each element of the array
 * represents a cell in the map, and '#' represents a wall or boundary.
 * @param player_y The parameter `player_y` represents the y-coordinate of the
 * player's position in the matrix.
 * @param player_x The parameter `player_x` represents the x-coordinate of the
 * player's position on the map.
 *
 * @return 1 if the player is inside the map (i.e., surrounded by '#') and 0
 * otherwise.
 */
static int	is_player_inside_map(char **matrix, int player_y, int player_x)
{
	int	row;
	int	col;

	row = player_y - 1;
	while (row >= 0 && matrix[row][player_x] != '#')
		row--;
	if (row < 0 || matrix[row][player_x] != '#')
		return (0);
	row = player_y + 1;
	while (matrix[row] && matrix[row][player_x] != '#')
		row++;
	if (matrix[row] == NULL || matrix[row][player_x] != '#')
		return (0);
	col = player_x - 1;
	while (col >= 0 && matrix[player_y][col] != '#')
		col--;
	if (col < 0 || matrix[player_y][col] != '#')
		return (0);
	col = player_x + 1;
	while (matrix[player_y][col] && matrix[player_y][col] != '#')
		col++;
	if (matrix[player_y][col] == '\0' || matrix[player_y][col] != '#')
		return (0);
	return (1);
}
