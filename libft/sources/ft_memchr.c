/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:45:11 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:53 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The memchr() function locates the first occurrence of c (converted to
*	an unsigned char) in string s.
*
*	RETURN VALUES
*	The memchr() function returns a pointer to the byte located, or NULL if
*	no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		++s;
	}
	return (NULL);
}
