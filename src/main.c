/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:39 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:17:40 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * This function sets up and runs a game using a map file.
 *
 * @param argc The `argc` parameter is an integer that represents the number of
 * command-line arguments passed to the program.
 * @param argv An array of strings representing the command-line arguments passed
 * to the program. The first element (argv[0]) is the name of the program itself,
 * and the following elements (argv[1], argv[2], etc.) are the arguments provided
 * by the user.
 *
 * @return The main function is returning 0.
 */
int	main(int argc, char *argv[])
{
	t_map_file	*map_file;
	t_data		*data;

	if (argc < 2)
		exit_error("Map file was not informed");
	if (argc > 2)
		exit_error("The program requires only one map file");
	map_file = get_map_file(argv[1]);
	setup(&data, map_file);
	key_hook(data);
	game(data);
	mlx_loop_hook(data->mlx, &game, data);
	mlx_loop(data->mlx);
	free_data(data);
	free_map_file(map_file);
	return (0);
}
