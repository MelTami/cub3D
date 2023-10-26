/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:42 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:33 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Deletes and frees the given element and every successor of that element,
*	using the function ’del’ and free(3). Finally, the pointer to the list must
*	be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (lst && (*del))
	{
		while (*lst)
		{
			elem = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(elem, (*del));
		}
		*lst = NULL;
	}
}
