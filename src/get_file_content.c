/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:13:48 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:13:49 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	remove_newline(char *line);

/**
 * The function "get_file_content" reads the contents of a file line by line and
 * stores them in a queue data structure.
 *
 * @param filename A string representing the name of the file to be read.
 *
 * @return a pointer to a t_queue structure, which represents the content of a
 * file.
 */
t_queue	*get_file_content(char *filename)
{
	int		fd;
	t_queue	*file_content;
	char	*line;

	file_content = queue_create();
	if (!file_content)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		queue_destroy(file_content);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		queue_push(file_content, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}

/**
 * The function removes the newline character from a given string.
 *
 * @param line A pointer to a character array representing a line of text.
 */
static void	remove_newline(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl)
		*nl = '\0';
}
