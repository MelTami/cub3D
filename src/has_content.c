#include "../inc/cub3D.h"

/**
 * The function checks if a string has any non-space characters.
 *
 * @param content The parameter "content" is a pointer to a character array
 * (string).
 *
 * @return 1 if the content string has non-space characters, and 0 if the content
 * string is empty or contains only spaces.
 */
int	has_content(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (content[i] != '\0');
}
