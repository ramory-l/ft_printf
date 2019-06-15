#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "get_next_line.h"
# include <stdarg.h>
# include <float.h>

# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_OCT 8
# define FLAG_ZERO 16

# define SIZE_LL 1
# define SIZE_L 2
# define SIZE_H 4
# define SIZE_HH 8
# define SIZE_LLL 16

/* Double defines */

# define MAX_POWER 10
# define BASE_INT 2
# define MAX_CELL 100000000
# define LEN_ARR 1500

/* */

typedef unsigned long long int ulli;
typedef long long int lli;
typedef const char cc;
typedef enum
{
	false,
	true
}		bool;

typedef struct	s_printf
{
	char		type;
	char		flags;
	unsigned	width;
	unsigned	accuracy;
	char		size;
	bool		sign;
	unsigned	len;
	bool		acc;
	unsigned	l_count;
	unsigned	count_l;
	unsigned	h_count;
	unsigned	printed;
}				t_printf;

typedef struct	s_buffer
{
	unsigned	s;
	char		temp[20];
	char		buffer[512];
}				t_buffer;

int				ft_printf(cc *format, ...);
cc				*ft_check_ptc(va_list ap, cc *format, t_printf *data, t_buffer *bf);
int				ft_specifier_format(cc *format, t_printf *data);
void			ft_choose_print(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_dioux_x(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_print_di(t_printf *data, t_buffer *bf);
void			ft_print_oux_x(t_printf *data, t_buffer *bf);
void			ft_print_char(va_list ap, t_printf *data, t_buffer *bf);
void			ft_print_string(va_list ap, t_printf *data, t_buffer *bf);
void			ft_print_percent(t_printf *data, t_buffer *bf);
void			ft_print_ptr(va_list ap, t_printf *data, t_buffer *bf);

/* Support functions */
int				type(char c);
void			ft_itoa_base(ulli value, int base, t_printf *data, t_buffer *bf);
void			ft_check_buffer(t_printf *data, t_buffer *bf);
void			ft_add_sign(t_printf *data, t_buffer *bf);
void			ft_fill_bf(t_printf *data, t_buffer *bf);
void			ft_fill_spaces_di(t_printf *data, t_buffer *bf);
void			ft_fill_zeroes_di(t_printf *data, t_buffer *bf);
void			ft_fill_spaces_oux(t_printf *data, t_buffer *bf);
void			ft_fill_zeroes_oux(t_printf *data, t_buffer *bf);

/* Double */

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
void		ft_longdouble(va_list ap, t_printf *data, t_buffer *bf);
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
void		ft_printlongdouble(char *result, t_printf *data, int sign, t_buffer *bf);
void		ft_printfractional(t_printf *data, char *result, t_buffer *bf);
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
