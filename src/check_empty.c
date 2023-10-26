/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:20 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:11:22 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	has_empty_rows(char **matrix);
static int	has_empty_columns(char **matrix);

/**
 * The function "check_empty" checks if a matrix has empty rows, empty columns,
 * or both, and exits the program with an error message if any of these 
 * conditions are met.
 *
 * @param map_file A pointer to a structure of type `t_map_file`.
 */
void	check_empty(t_map_file *map_file)
{
	char	*err_msg;
	int		empty_rows;
	int		empty_columns;

	err_msg = NULL;
	empty_rows = has_empty_rows(map_file->matrix);
	empty_columns = has_empty_columns(map_file->matrix);
	if (empty_rows && empty_columns)
		err_msg = "Has empty rows and columns in map";
	else if (empty_rows)
		err_msg = "Has empty rows in map";
	else if (empty_columns)
		err_msg = "Has empty columns in map";
	if (err_msg)
	{
		free_map_file(map_file);
		exit_error(err_msg);
	}
}

/**
 * The function "has_empty_rows" checks if a matrix has any empty rows.
 *
 * @param matrix A pointer to a pointer of characters, representing a matrix or a
 * 2D array of strings.
 *
 * @return a boolean value indicating whether there are any empty rows in the
 * matrix. If there are empty rows, the function returns 1 (true), otherwise it
 * returns 0 (false).
 */
static int	has_empty_rows(char **matrix)
{
	int	row;
	int	empty_rows;

	row = 0;
	empty_rows = 0;
	while (matrix[row])
	{
		if (!has_content(matrix[row]))
			empty_rows++;
		row++;
	}
	return (empty_rows > 0);
}

/**
 * The function "has_empty_columns" checks if there are any empty columns in a
 * given matrix.
 *
 * @param matrix A 2D array of characters representing a matrix. Each element in
 * the matrix is a character.
 *
 * @return a boolean value indicating whether there are any empty columns in the
 * matrix.
 */
static int	has_empty_columns(char **matrix)
{
	int	row;
	int	col;
	int	empty;
	int	empty_columns;

	col = 0;
	row = 0;
	empty = 1;
	empty_columns = 0;
	while (matrix[row])
	{
		if (matrix[row][col] != ' ')
			empty = 0;
		row++;
		if (!matrix[row])
		{
			empty_columns += empty;
			col++;
			row = 0;
			empty = 1;
			if (!matrix[row][col])
				break ;
		}
	}
	return (empty_columns > 0);
}
