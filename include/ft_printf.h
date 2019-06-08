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
	unsigned long		unsignedlong;
	long double			longdouble;
}						longdoubletounsignedlong;

typedef struct			t_longdouble
{
	int					sign;
	int					exp;
	unsigned long		mantis;
}						s_longdouble;

typedef struct			t_arrayint
{
	unsigned long int	intresult[LEN_ARR];
	unsigned long int	inttmp[LEN_ARR];
	int					lenarr;
	int					iarr;
	int					jarr;
}						s_arrayint;

typedef struct			t_powerbits
{
	int 				power;
	int 				countpower;
	int 				remainpower;
	int					base;
	int					numofbits;
	int					flag;
}						s_powerbits;

typedef struct			t_doubletochar
{
	char *inttochar;
	char *nulls;
	char *fractiontochar;
}						s_doubletochar;

void	ft_print_int(int nbr);
void	ft_longdouble(long double number, long long accuracy);

#endif
