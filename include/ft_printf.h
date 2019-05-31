#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <float.h>
# include <stdlib.h>

#define MAX_POWER 10
#define BASE_INT 2
#define MAX_CELL 100000000
#define LEN_ARR 1500

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
	unsigned long int	intResult[LEN_ARR];
	unsigned long int	intTmp[LEN_ARR];
	int					lenArr;
	int					iArr;
	int					jArr;
	int					flagInt;
}						s_arrayInt;

typedef struct			t_powerBits
{
	int 				power;
	int 				countPower;
	int 				remainPower;
	int					base;
}						s_powerBits;

typedef struct			t_doubleToChar
{
	char *intToChar;
	char *nulls;
	char *fractionToChar;
}						s_doubleToChar;



void	ft_print_int(int nbr);
void	ft_longDouble(long double nbr, unsigned int accuracy);

#endif
