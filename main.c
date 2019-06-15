#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	// ft_printf("%5d\n", 42);
	// int d = ft_printf("mine dasdds  dasda\n");

	// printf("orig %X\n", 42);
	// ft_printf("mine %X\n", 42);
	// ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	// printf("@moulitest: %5.x %5.0x\n", 0, 0);
	// ft_printf("% d", -42);
	// ft_printf("%-+10.5d\n", 4242);
	// ft_printf("%+10.5d\n", 4242);
	// ft_printf("%+10.5d\n", 4242);
	// ft_printf("%4.15d\n", 42);
	// ft_printf("%10.5d\n", 4242);
	// ft_printf("%4.15d", 42);
	// ft_printf("%d", -2151);
	// printf("%6.1d\n", -1234);
	int d = ft_printf("%lld\n", LLONG_MAX);
	int dd = printf("%lld\n", LLONG_MAX);
	ft_printf("mine **%d**", dd);
	printf("orig **%d**", dd);
	return (0);
}
