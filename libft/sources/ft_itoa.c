/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:56:18 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:11 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a string representing the
*	integer received as an argument. Negative numbers must be handled.
*
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	len = (int)ft_nbrlen(n, 10);
	if (n < 0)
	{
		n = -n;
		++len;
	}
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (len > 0)
		str[--len] = '-';
	return (str);
}
