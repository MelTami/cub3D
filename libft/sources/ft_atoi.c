/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:02:51 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:37 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The atoi() function converts the initial portion of the string pointed
*	to by str to int representation.
*/

int	ft_atoi(const char *str)
{
	signed char		sign;
	unsigned int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (*(str++) - '0');
	return (nbr * sign);
}
