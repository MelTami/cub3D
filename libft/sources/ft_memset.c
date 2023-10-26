/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:20:56 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:12:05 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The memset() function writes len bytes of value c (converted to an
*	unsigned char) to the string b.
*
*	RETURN VALUES
*	The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_ptr;

	b_ptr = (unsigned char *)b;
	while (len--)
		*(b_ptr++) = (unsigned char)c;
	return (b);
}
