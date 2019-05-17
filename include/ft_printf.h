#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>

// typedef union
// {
// 	__uint128_t u_int128;
// 	long double l_dbl;
// }				lngdbltouint128;

// typedef union
// {
// 	long lng;
// 	double dbl;
// }				dbltolng;

// struct	sem_long_double
// {
// 	int sign;
// 	int exp;
// 	long long mantis;
// };

// typedef struct	t_array
// {
// 	int mantis_arr[1000];
// 	int len_arr;
// 	int tmp;
// 	int temp;
// 	int base;
// }				s_array;

// typedef struct	tt_array
// {
// 	int mantis_arr[35000];
// 	int len_arr;
// 	int tmp;
// 	int temp;
// 	int base;
// }				ss_array;

// struct	sem_double 
// {
// 	int sign;
// 	int exp;
// 	long mantis;
// };

int		ft_printf(const char *format, ...);
void	ft_print_int(int nbr);
// void    ft_double(double nbr);
void	ft_long_double(long double nbr);

#endif