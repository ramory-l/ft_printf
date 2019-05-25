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

// подсчет степеней
static s_arrayInt	ft_calcPower(s_arrayInt arrayInt, int power)
{
	arrayInt.flag = 0;
	int tmp_flag;
	unsigned long long int current = 0;

	if (arrayInt.intTmp[arrayInt.iArr] == 0)
	{
		arrayInt.intTmp[arrayInt.iArr] = ft_exponentiation(power, BASE_INT);
		arrayInt.remainder = 0;
		arrayInt.flag++;
	}
	tmp_flag = arrayInt.flag;
	while (arrayInt.iArr < arrayInt.flag - 1 || arrayInt.remainder)
	{
		current = arrayInt.remainder + arrayInt.intTmp[arrayInt.iArr] * ft_exponentiation(power, BASE_INT);
		arrayInt.intTmp[arrayInt.iArr] = current % MAX_CELL;
		arrayInt.remainder = current / MAX_CELL;
		arrayInt.iArr++;
		arrayInt.intTmp[arrayInt.iArr] = current / MAX_CELL;
		if ((arrayInt.iArr > tmp_flag - 1) && arrayInt.remainder)
			tmp_flag++;
	}
	arrayInt.flag = tmp_flag;
	return (arrayInt);
}

// заполнение массива
static void		ft_fillArray(s_powerBits bitsPower)
{
	s_arrayInt arrayInt;

	arrayInt.flag = 0;
	while (bitsPower.countPower--)
		arrayInt = ft_calcPower(arrayInt, MAX_POWER);
	if (bitsPower.remainPower)
		arrayInt = ft_calcPower(arrayInt, bitsPower.remainPower);
	else
		arrayInt = ft_calcPower(arrayInt, bitsPower.power);
}

// разбивка степеней
static void		ft_separationPower(s_powerBits bitsPower)
{
	bitsPower.countPower = 0;
	bitsPower.remainPower = 0;
	if (bitsPower.power > 10)
    {
        bitsPower.countPower = bitsPower.power / 10;
        bitsPower.remainPower = bitsPower.power % 10;
    }
	ft_fillArray(bitsPower);
}

/*// сложение массивов
static s_arrayInt	ft_summPower(s_arrayInt arrayInt)
{
 df
}*/

// поиск степеней из бинарной мантисы
static void		ft_findingIntPower(s_longDouble longDouble)
{
	s_powerBits	bitsPower;
	s_arrayInt	arrayInt;
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
//			if (arrayInt.intResult)
//				ft_summPower(arrayInt);
//			else
//				arrayInt.intResult = arrayInt.intTmp;
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
	s_longDouble 				longDouble;

	bits.longDouble = number;
	longDouble.sign = (*(&bits.unsignedLong + 1)) & (1 << 15);
	longDouble.exp = (int)(*(&bits.unsignedLong + 1) & 0x7fffL);
	longDouble.mantis = bits.unsignedLong;
	ft_printBitsUnsignedLong(longDouble.mantis);
	ft_findingIntPower(longDouble);
}
