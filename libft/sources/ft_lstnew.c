/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:33:52 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:11:47 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new element. The variable
*	’content’ is initialized with the value of the parameter ’content’. The
*	variable ’next’ is initialized to NULL.
*
*	RETURN VALUES
*	The new element.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new)
	{
		new->content = content;
		new->next = 0;
	}
	return (new);
}
