#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H
# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <float.h>
# include <stdlib.h>
# define MAX_POWER 10
# define BASE_INT 2
# define MAX_CELL 100000000
# define LEN_ARR 1500

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

void		ft_print_int(int nbr);
void		ft_longdouble(long double number, long long accuracy);
int			ft_minpowerfractional(unsigned long mantis);
char		*ft_numtochar(s_arrayint arrayint);
s_powerbits	ft_bitspowercontructor(s_powerbits bitspower);
s_arrayint	ft_fillarray(s_powerbits bitspower, s_arrayint arrayint);
char		*ft_workwithmantis(s_longdouble longdouble);
s_arrayint	ft_findingintpower(s_longdouble longdouble,
int numofintbits, s_powerbits bitspower);
s_arrayint	ft_findingfractionpower(s_longdouble longdouble,
int numofintbits, s_powerbits bitspower);
char		*ft_fillnulls(int exp, char *fraction, unsigned long mantis);
s_arrayint	ft_multlongnumbyashort(s_arrayint arrayint, int power, int base);
s_arrayint	ft_multlongnumbyaten(s_arrayint arrayint);
int			ft_exponentiation(int power, int number);
s_arrayint	ft_summpower(s_arrayint arrayint);
int			ft_maxindex(s_arrayint arrayint);
void		ft_printlongdouble(char *result, long long accuracy, int sign);
void		ft_printfractional(long long accuracy, char *result);
char		*ft_rounding(char *result, long long accuracy);
char		*ft_rounding_fraction(char *result, long long accuracy);
char		*ft_if_five_in_fractional(char *result,
int check, long long accuracy);
char		*ft_replace_num_round(int check, long long accuracy,
char *result);
s_arrayint	ft_bzeroarrs(void);
s_arrayint	ft_bzerotmparr(s_arrayint arrayint);
s_arrayint	ft_separationpower(s_powerbits bitspower,
s_arrayint arrayint);
s_arrayint	ft_bitsandpower(s_arrayint arrayint, s_powerbits bitspower);

#endif
