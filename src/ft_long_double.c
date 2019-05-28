#include "ft_printf.h"

// вспомогательная функция для вывода заполненых ячеек на экран
static void		ft_printCellArr(s_arrayInt arrayInt)
{
	int iTemp;
	int iArr;

	iTemp = arrayInt.iArr - 1;
	iArr = 0;
	while (iTemp >= 0)
	{
		printf("%lu\n", arrayInt.intResult[iArr]);
		iArr++;
		iTemp--;
	}
}

// заполнение массивов нулями
static s_arrayInt	ft_bzeroArrs(void)
{
	s_arrayInt arrayInt;
	int lenArr;
	int iArr;

	iArr = 0;
	lenArr = 1500;
	arrayInt.lenArr = 1500;
	while (lenArr--)
	{
		arrayInt.intResult[iArr] = 0;
		arrayInt.intTmp[iArr] = 0;
		iArr++;
	}
	arrayInt.iArr = 0;
	arrayInt.jArr = 0;
	return (arrayInt);
}

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

// умножение длинного на короткое
static s_arrayInt	ft_multLongNumByAShort(s_arrayInt arrayInt, int power, int base)
{
	unsigned long long int current;
	unsigned long long int remainder;
	int jArr;

	jArr = 0;
	remainder = 0;
	current = 0;
	while (jArr <= arrayInt.jArr || remainder)
	{
		if (jArr == arrayInt.lenArr)
			return (arrayInt);
		if (arrayInt.intTmp[jArr] != 0)
			current = remainder + arrayInt.intTmp[jArr] * ft_exponentiation(power, base);
		else
			current = remainder + ft_exponentiation(power, base);
		arrayInt.intTmp[jArr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		jArr++;
	}
	arrayInt.jArr = jArr;
	return (arrayInt);
}

// заполнение массива
static s_arrayInt		ft_fillArray(s_powerBits bitsPower, s_arrayInt arrayInt)
{
	while (bitsPower.countPower--)
		arrayInt = ft_multLongNumByAShort(arrayInt, MAX_POWER, bitsPower.base);
	if (bitsPower.remainPower)
		arrayInt = ft_multLongNumByAShort(arrayInt, bitsPower.remainPower, bitsPower.base);
	else
		arrayInt = ft_multLongNumByAShort(arrayInt, bitsPower.power, bitsPower.base);
	return (arrayInt);
}

// разбивка степеней
static s_arrayInt	ft_separationPower(s_powerBits bitsPower, s_arrayInt arrayInt)
{
	bitsPower.countPower = 0;
	bitsPower.remainPower = 0;
	if (bitsPower.power > 10)
    {
        bitsPower.countPower = bitsPower.power / 10;
        bitsPower.remainPower = bitsPower.power % 10;
    }
	return (ft_fillArray(bitsPower, arrayInt));
}

// определение максимального значения индекса
static int	ft_maxIndex(s_arrayInt arrayInt)
{
	return (arrayInt.iArr > arrayInt.jArr ? arrayInt.iArr : arrayInt.jArr);
}

// сложение массивов
static s_arrayInt	ft_summPower(s_arrayInt arrayInt)
{
	unsigned long long int remminder;
	unsigned long long int current;
	int iArr;

	remminder = 0;
	iArr = 0;
	current = 0;
	while (iArr < ft_maxIndex(arrayInt) || remminder)
	{
		if (iArr == arrayInt.lenArr)
			return (arrayInt);
		current += remminder + (iArr < arrayInt.lenArr ? arrayInt.intTmp[iArr] : 0);
		remminder = current / MAX_CELL;
		if (current)
			arrayInt.intResult[iArr] += current % MAX_CELL;
		iArr++; 
	}
	arrayInt.iArr = iArr;
	return (arrayInt);
}

// очистка массива intTmp
static s_arrayInt	ft_bzeroTmpArr(s_arrayInt	arrayInt)
{
	int iArr;
	int lenArr;

	lenArr = arrayInt.jArr;
	iArr = 0;
	while (lenArr--)
	{
		arrayInt.intTmp[iArr] = 0;
		iArr++;
	}
	arrayInt.jArr = 0;
	return (arrayInt);
}

// поиск степеней для целого числа из бинарной мантисы
static s_arrayInt		ft_findingIntPower(s_longDouble longDouble, int numOfIntBits, s_powerBits bitsPower)
{
	int 		numOfBits;
	int 		bit;
	s_arrayInt	arrayInt;

	bit = 0;
	numOfBits = 63;
	bitsPower.base = 2;
	arrayInt = ft_bzeroArrs();
	while (numOfIntBits)
	{
		bit = ((longDouble.mantis & (1UL << numOfBits)) != 0) ? 1 : 0;
		numOfBits--;
		bitsPower.power--;
		if (bit == 1)
		{
			printf("2^%d\n", bitsPower.power);
			arrayInt = ft_separationPower(bitsPower, arrayInt);
			arrayInt = ft_summPower(arrayInt);
			arrayInt = ft_bzeroTmpArr(arrayInt);
		}
		numOfIntBits--;
	}
	ft_printCellArr(arrayInt);
	return (arrayInt);
}

// поиск степеней для дробного числа из бинарной мантисы
static s_arrayInt		ft_findingFractionPower(s_longDouble longDouble, int numOfIntBits, s_powerBits bitsPower)
{
	int 		numOfBits;
	int 		bit;
	s_arrayInt	arrayInt;
	int 		flag;

	flag = 0;
	bit = 0;
	numOfBits = 63;
	bitsPower.base = 5;
	bitsPower.power = 0;
	arrayInt = ft_bzeroArrs();
	while (numOfBits)
	{
		bit = ((longDouble.mantis & (1UL << numOfBits)) != 0) ? 1 : 0;
		numOfIntBits--;
		numOfBits--;
		if (numOfIntBits < 0)
		{
			bitsPower.power++;
			if (bit == 1)
			{
				flag = 1;
				printf("5^-%d\n", bitsPower.power);
				arrayInt = ft_separationPower(bitsPower, arrayInt);
				arrayInt = ft_summPower(arrayInt);
				arrayInt = ft_bzeroTmpArr(arrayInt);
			}
			if (flag == 1)
				arrayInt = ft_multLongNumByATen(arrayInt, 1, 10);
		}
	}
	// ft_printCellArr(arrayInt);
	return (arrayInt);
}

// перевод чисел в символы
static char		*ft_numToChar(s_arrayInt arrayInt)
{
	char 	*result;
	char	*tmp;
	int 	i;

	i = 0;
	result = "\0";
	while (i != arrayInt.iArr)
	{
		tmp = ft_itoa(arrayInt.intResult[i]);
		result = ft_strjoin(result, tmp);
		i++;
	}
	return (result);
}

// работа с мантисой
static char		*ft_workWithMantis(s_longDouble longDouble)
{
	s_powerBits					bitsPower;
	int 						numOfIntBits;
	s_arrayInt					arrayInt;
	s_doubleToChar				doubleChar;
	char 						*result = NULL;

	numOfIntBits = longDouble.exp - LDBL_MAX_EXP + 2;
	bitsPower.power = numOfIntBits;
	arrayInt = ft_findingIntPower(longDouble, numOfIntBits, bitsPower);
	doubleChar.intToChar = ft_numToChar(arrayInt);
	arrayInt = ft_findingFractionPower(longDouble, numOfIntBits, bitsPower);
	// doubleChar.fractionToChar = ft_numToChar(arrayInt);
	// result = ft_strjoin(doubleChar.intToChar, ".");
	// result = ft_strjoin(result, doubleChar.fractionToChar);
	return (result);
}

// тут начинается магия
void    ft_longDouble(long double number)
{
	longDoubleToUnsignedLong	bits;
	s_longDouble 				longDouble;
	char 						*result;

	bits.longDouble = number;
	longDouble.sign = (*(&bits.unsignedLong + 1)) & (1 << 15);
	longDouble.exp = (int)(*(&bits.unsignedLong + 1) & 0x7fffL);
	longDouble.mantis = bits.unsignedLong;
	ft_printBitsUnsignedLong(longDouble.mantis);
	result = ft_workWithMantis(longDouble);
}
// не забудь free