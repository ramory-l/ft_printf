#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>


int		ft_printf(const char *format, ...);
void	ft_manage_percent(const char *format, va_list ap);
int		ft_print_number(unsigned long long int number, char c);

#endif