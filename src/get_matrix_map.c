/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:19 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:15:20 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include <stddef.h>
#include <stdlib.h>

static int		make_lines_same_len(t_queue *file_content);
static size_t	get_longest_line_len(t_queue *file_content);
static char		*get_padded_line(char *line, size_t size);

/**
 * The function "get_matrix_map" takes a queue of file content, ensures that all
 * lines in the queue have the same length, and then returns a matrix (2D array)
 * representation of the file content.
 *
 * @param file_content A pointer to a queue data structure that contains the
 * content of a file.
 *
 * @return a pointer to a 2D array of characters (char **).
 */
char	**get_matrix_map(t_queue *file_content)
{
	char	**matrix;
	char	*value;

	if (!file_content || file_content->len == 0)
		return (NULL);
	if (make_lines_same_len(file_content) != 0)
		return (NULL);
	matrix = (char **)malloc((file_content->len + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[file_content->len] = NULL;
	while (file_content->len > 0)
	{
		value = file_content->last->value;
		file_content->last->value = NULL;
		matrix[file_content->len - 1] = value;
		queue_pop(file_content);
	}
	return (matrix);
}

/**
 * The function "make_lines_same_len" pads each line in a queue with spaces to
 * make them all the same length as the longest line in the queue.
 *
 * @param file_content A pointer to a queue structure that contains the content
 * of a file.
 *
 * @return an integer value. If the function is successful, it will return 0. 
 * If there is an error, it will return -1.
 */

static int	make_lines_same_len(t_queue *file_content)
{
	t_queue_item	*tmp;
	char			*value;
	size_t			longest_line_len;

	longest_line_len = get_longest_line_len(file_content);
	tmp = file_content->first;
	while (tmp)
	{
		value = get_padded_line(tmp->value, longest_line_len);
		if (!value)
			return (-1);
		free(tmp->value);
		tmp->value = value;
		tmp = tmp->next;
	}
	return (0);
}

/**
* The function "get_longest_line_len" returns the length of the longest line in a
* queue of strings.
*
* @param file_content A pointer to a queue structure that contains the content of
* a file.
*
* @return the length of the longest line in the given file content.
*/
static size_t	get_longest_line_len(t_queue *file_content)
{
	t_queue_item	*tmp;
	size_t			len;
	size_t			longest_len;

	tmp = file_content->first;
	longest_len = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->value);
		if (len > longest_len)
			longest_len = len;
		tmp = tmp->next;
	}
	return (longest_len);
}

/**
* The function "get_padded_line" takes a line of text and pads it with spaces 
* to a specified size.
*
* @param line A pointer to a character array representing a line of text.
* @param size The size parameter represents the desired size of the padded line.
*
* @return a pointer to a character array (string) that represents 
* the padded line.
*/

static char	*get_padded_line(char *line, size_t size)
{
	char	*padded_line;
	size_t	len;
	size_t	i;

	len = ft_strlen(line);
	if (len == size)
		return (ft_strdup(line));
	padded_line = (char *)malloc((size + 1) * sizeof(char));
	if (!padded_line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (i < len)
			padded_line[i] = line[i];
		else
			padded_line[i] = ' ';
		i++;
	}
	padded_line[i] = '\0';
	return (padded_line);
}
