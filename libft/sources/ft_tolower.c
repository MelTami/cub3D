/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:40:09 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:13:19 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The tolower() function converts an upper-case letter to the
*	corresponding lower-case letter.  The argument must be representable as
*	an unsigned char or the value of EOF.
*
*	RETURN VALUES
*	If the argument is an upper-case letter, the tolower() function returns
*	the corresponding lower-case letter if there is one; otherwise, the
*	argument is returned unchanged.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
