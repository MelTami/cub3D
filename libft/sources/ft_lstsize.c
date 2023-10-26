/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:37:26 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:50 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Counts the number of elements in a list.
*
*	RETURN VALUES
*	Length of the list.
*/

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		size;

	elem = lst;
	size = 0;
	while (elem)
	{
		elem = elem->next;
		++size;
	}
	return (size);
}
