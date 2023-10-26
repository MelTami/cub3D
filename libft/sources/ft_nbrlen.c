/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:18:47 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:12:08 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(ssize_t nbr, int base)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= base;
		++len;
	}
	return (len);
}
