/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:35:49 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:20 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Adds the element ’new’ at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst && new)
	{
		elem = *lst;
		*lst = new;
		(*lst)->next = elem;
	}
}
