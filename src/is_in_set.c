/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:42 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:43 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function checks if a given character is present in a given set of
 * characters.
 *
 * @param c The parameter "c" is a character that we want to check if it is in
 * the set.
 * @param set The parameter "set" is a pointer to a character array.
 *
 * @return The function is_in_set is returning an integer value. It returns 1 if
 * the character c is found in the set, and 0 otherwise.
 */
int	is_in_set(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
