/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:56 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:57 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function "game" updates and renders data, and returns 1.
 *
 * @param data The parameter "data" is a pointer to a structure of type "t_data".
 *
 * @return 1.
 */
int	game(t_data *data)
{
	update(data);
	render(data);
	return (1);
}
