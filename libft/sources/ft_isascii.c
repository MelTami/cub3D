/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:25 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:56 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The isascii() function tests for an ASCII character, which is any
*	character between 0 and octal 0177 inclusive.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
