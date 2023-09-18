#include "../inc/cub3D.h"

/**
 * The function "exit_error" prints an error message to the standard error stream
 * and exits the program with a status code of 1.
 *
 * @param err The parameter "err" is a pointer to a character array (string) that
 * represents the error message to be displayed.
 */
void	exit_error(char *err)
{
	ft_putendl_fd("Error", STDERR);
	ft_putendl_fd(err, STDERR);
	exit(1);
}
