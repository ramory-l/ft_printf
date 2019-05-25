#include "ft_printf.h"

// вывод битов unsigned long
static void		ft_printBitsUnsignedLong(unsigned long number)
{
	int	numBits;

	numBits = 63;
	while (numBits >= 0)
	{
		(number & (1UL << numBits)) != 0 ? write(1, "1", 1) : write(1, "0", 1);
		numBits--;
	}
	write(1, "\n\n", 2);
}

// возведение в степень
static int		ft_exponentiation(int power, int number)
{
	int result;

	result = number;
	if (power == 0)
		result = 1;
	else
		while (power-- != 1)
			result *= number;
	return (result);
}

//разделение числа по ячейкам
static t_arrayInt		ft_separationNumber(t_arrayInt arrayInt, int check_result)
{
	int num1;
	int num2;

	num1 = check_result / 100000000;
	num2 = check_result % 100000000;

}

// заполнение массива
static void		ft_fillArray(t_powerBits bitsPower)
{
	t_arrayInt arrayInt;
	int check_result;
	int iArr;

	iArr = 0;
	check_result = 0;
	while (bitsPower.countPower--)
	{
		if (iArr == 0 && arrayInt.intResult[iArr] == 0)
			arrayInt.intResult[iArr] = ft_exponentiation(MAX_POWER, BASE_INT);
		else
		{
			check_result = arrayInt.intResult[iArr] * ft_exponentiation(MAX_POWER, BASE_INT);
			if (check_result > MAX_CELL)
				arrayInt = ft_separationNumber(arrayInt, check_result);
			else
				arrayInt.intResult[iArr] = check_result;
		}
	}
}

// разбивка степеней
static void		ft_separationPower(t_powerBits bitsPower)
{
	if (bitsPower.power > 10)
    {
        bitsPower.countPower = bitsPower.power / 10;
        bitsPower.remainPower = bitsPower.power % 10;
    }
	ft_fillArray(bitsPower);
}

// поиск степеней из бинарной мантисы
static void		ft_findingIntPower(t_longDouble longDouble)
{
	t_powerBits	bitsPower;
	int 		numOfIntBits;
	int 		numOfBits;
	int 		bit;

	bit = 0;
	numOfBits = 63;
	numOfIntBits = longDouble.exp - LDBL_MAX_EXP + 2;
	bitsPower.power = numOfIntBits;
	while (numOfIntBits)
	{
		bit = ((longDouble.mantis & (1UL << numOfBits)) != 0) ? 1 : 0;
		numOfBits--;
		bitsPower.power--;
		if (bit == 1)
		{
			printf("2^%d\n", bitsPower.power);
			ft_separationPower(bitsPower);
		}
		numOfIntBits--;
	}
}

// тут начинается магия
void    ft_longDouble(long double number)
{
	longDoubleToUnsignedLong	bits;
	t_longDouble 				longDouble;

	bits.longDouble = number;
	longDouble.sign = (*(&bits.unsignedLong + 1)) & (1 << 15);
	longDouble.exp = (int)(*(&bits.unsignedLong + 1) & 0x7fffL);
	longDouble.mantis = bits.unsignedLong;
	ft_printBitsUnsignedLong(longDouble.mantis);
	ft_findingIntPower(longDouble);
}
