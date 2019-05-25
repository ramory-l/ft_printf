#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <float.h>

#define MAX_POWER 10
#define BASE_INT 2
#define MAX_CELL 100000000

typedef union
{
	unsigned long		unsignedLong;
	long double			longDouble;
}						longDoubleToUnsignedLong;

typedef struct			t_longDouble
{
	int					sign;
	int					exp;
	unsigned long		mantis;
}						s_longDouble;

typedef struct			t_arrayInt
{
	unsigned long int	intResult[1500];
	unsigned long int	intTmp[1500];
	int 				flag;
	unsigned long int	remainder;
	int					iArr;
	int					jArr;
}						s_arrayInt;

typedef struct			t_powerBits
{
	int 				power;
	int 				countPower;
	int 				remainPower;
}						s_powerBits;


void	ft_print_int(int nbr);
void	ft_longDouble(long double nbr);

#endif
