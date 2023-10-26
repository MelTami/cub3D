/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:11:55 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:12:05 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**
 * The function "count_char" counts the number of occurrences of a specific
 * character in a given string.
 *
 * @param str A pointer to a character array (string) that we want to count the
 * occurrences of a specific character in.
 * @param c The parameter "c" in the count_char function is a character that we
 * want to count the occurrences of in the string "str".
 *
 * @return the count of occurrences of the character 'c' in the string 'str'.
 */
size_t	count_char(char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
