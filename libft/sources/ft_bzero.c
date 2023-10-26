/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:27:33 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:40 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The bzero() function writes n zeroed bytes to the string s.
*	If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)(s++) = 0;
}
