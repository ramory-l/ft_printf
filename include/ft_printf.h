#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <float.h>

#define MAX_POWER 10
#define BASE_INT 2
#define MAX_CELL 9999999

typedef union
{
	unsigned long		unsignedLong;
	long double			longDouble;
}						longDoubleToUnsignedLong;

typedef struct			s_longDouble
{
	int					sign;
	int					exp;
	unsigned long		mantis;
}						t_longDouble;

typedef struct			s_arrayInt
{
	unsigned long int	intResult[1500];
	unsigned long int	intTmp[1500];
}						t_arrayInt;

typedef struct			s_powerBits
{
	int 				power;
	int 				countPower;
	int 				remainPower;
}						t_powerBits;


void	ft_print_int(int nbr);
void	ft_longDouble(long double nbr);

#endif
