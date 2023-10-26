/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:58 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:39 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
*	element.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	if (lst && (*f))
	{
		elem = lst;
		while (elem)
		{
			(*f)(elem->content);
			elem = elem->next;
		}
	}
}
