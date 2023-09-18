/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:13:55 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:12:17 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Outputs the integer ’n’ to the given file descriptor.
*/

static void	ft_putnbr(int n, int fd)
{
	char	str[11];
	int		nbr;
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	nbr = n;
	while (nbr)
	{
		++i;
		nbr /= 10;
	}
	str[i] = '\0';
	while (i-- && n)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, str, ft_strlen(str));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr(n, fd);
}
