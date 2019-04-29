#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>


int		ft_printf(const char *format, ...);
void	ft_print_int(int nbr);
void	ft_print_fpn(double nbr, unsigned int nbr_sign);

#endif