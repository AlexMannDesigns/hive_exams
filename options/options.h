#ifndef OPTIONS_H
# define OPTIONS_H

#include <unistd.h>

# define USAGE "options: abcdefghijklmnopqrstuvwxyz"

int	check_flags(char **av);
void	options_control(char **av);
#endif
