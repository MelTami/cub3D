/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:16:06 by lbatista          #+#    #+#             */
/*   Updated: 2023/09/15 13:12:35 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strdup() function allocates sufficient memory for a copy of the
*	string s1, does the copy, and returns a pointer to it. The pointer may
*	subsequently be used as an argument to the function free(3).
*
*	If insufficient memory is available, NULL is returned and errno is set
*	to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(len * sizeof(*s1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
