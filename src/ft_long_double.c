#include "ft_printf.h"

// // вспомогательная функция для вывода заполненых ячеек на экран
// static void		ft_printCellArr(s_arrayInt arrayInt)
// {
// 	int iTemp;
// 	int iArr;

// 	iTemp = arrayInt.iArr - 1;
// 	iArr = 0;
// 	while (iTemp >= 0)
// 	{
// 		printf("%lu\n", arrayInt.intResult[iArr]);
// 		iArr++;
// 		iTemp--;
// 	}
// }

// заполнение массивов нулями
static s_arrayInt	ft_bzeroArrs(void)
{
	s_arrayInt arrayInt;
	int lenArr;
	int iArr;

	iArr = 0;
	lenArr = LEN_ARR;
	arrayInt.lenArr = LEN_ARR;
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

// // вывод битов unsigned long
// static void		ft_printBitsUnsignedLong(unsigned long number)
// {
// 	int	numBits;

// 	numBits = 63;
// 	while (numBits >= 0)
// 	{
// 		(number & (1UL << numBits)) != 0 ? write(1, "1", 1) : write(1, "0", 1);
// 		numBits--;
// 	}
// 	write(1, "\n\n", 2);
// }

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
	if (arrayInt.intTmp[jArr] == 0)
	{
		arrayInt.intTmp[jArr] = ft_exponentiation(power, base);
		jArr++;
	}
	while (jArr < arrayInt.jArr || remainder)
	{
		if (jArr == arrayInt.lenArr)
			return (arrayInt);
		current = remainder + arrayInt.intTmp[jArr] * ft_exponentiation(power, base);
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
	if (bitsPower.countPower)  {
		while (bitsPower.countPower--)
			arrayInt = ft_multLongNumByAShort(arrayInt, MAX_POWER, bitsPower.base);
	}
	if (bitsPower.remainPower || (!bitsPower.remainPower && !bitsPower.countPower))
		arrayInt = ft_multLongNumByAShort(arrayInt, bitsPower.remainPower, bitsPower.base);
	return (arrayInt);
}

// разбивка степеней
static s_arrayInt	ft_separationPower(s_powerBits bitsPower, s_arrayInt arrayInt)
{
	bitsPower.countPower = 0;
	bitsPower.remainPower = 0;
	if (bitsPower.power >= MAX_POWER)
    {
        bitsPower.countPower = bitsPower.power / MAX_POWER;
    }
	bitsPower.remainPower = bitsPower.power % MAX_POWER;
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
		current = arrayInt.intResult[iArr] + arrayInt.intTmp[iArr] + remminder;
		remminder = current / MAX_CELL;
		if (current)
			arrayInt.intResult[iArr] = current % MAX_CELL;
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
	while (numOfBits >= 0)
	{
		bit = ((longDouble.mantis & (1UL << numOfBits)) != 0) ? 1 : 0;
		numOfBits--;
		bitsPower.power--;
		if (bitsPower.power < 0)
			return (arrayInt);
		if (bit == 1)
		{
			// printf("2^%d\n", bitsPower.power);
			arrayInt = ft_separationPower(bitsPower, arrayInt);
			arrayInt = ft_summPower(arrayInt);
			arrayInt = ft_bzeroTmpArr(arrayInt);
		}
		numOfIntBits--;
	}
	// ft_printCellArr(arrayInt);
	return (arrayInt);
}

// умножение длинного числа на 10
static s_arrayInt		ft_multLongNumByATen(s_arrayInt arrayInt)
{
	unsigned long long int current;
	unsigned long long int remainder;
	int iArr;

	iArr = 0;
	remainder = 0;
	current = 0;
	while (iArr < arrayInt.iArr || remainder)
	{
		if (iArr == arrayInt.lenArr)
			return (arrayInt);
		if (arrayInt.intResult[iArr] != 0)
			current = remainder + arrayInt.intResult[iArr] * 10;
		else
			current = remainder;
		arrayInt.intResult[iArr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		iArr++;
	}
	arrayInt.iArr = iArr;
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
	if (bitsPower.power < 0)
		bitsPower.power *= -1;
	else
		bitsPower.power = 0;
	arrayInt = ft_bzeroArrs();
	while (numOfBits >= 0)
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
				// printf("5^%d\n", bitsPower.power);
				arrayInt = ft_separationPower(bitsPower, arrayInt);
				arrayInt = ft_summPower(arrayInt);
				arrayInt = ft_bzeroTmpArr(arrayInt);
			}
			if (flag == 1 && (longDouble.mantis << (63 - numOfBits)) != 0)
				arrayInt = ft_multLongNumByATen(arrayInt);
		}
	}
	return (arrayInt);
}

// перевод чисел в символы
static char		*ft_numToChar(s_arrayInt arrayInt)
{
	char 	*result;
	char	*tmp;
	int 	i;
	int		lenArr;
	char 	*nulls;

	i = --arrayInt.iArr;
	result = "\0";
	while (i >= 0)
	{
		tmp = ft_itoa(arrayInt.intResult[i]);
		lenArr = ft_strlen(tmp);
		if (lenArr != 8 && *result)
		{
			nulls = (char*)malloc((8 - lenArr + 1) * sizeof(char));
			nulls[8 - lenArr] = '\0';
			nulls = ft_memset(nulls, '0', 8 - lenArr);
			tmp = ft_strjoin(nulls, tmp);
			free(nulls);
		}
		result = ft_strjoin(result, tmp);
		i--;
	}
	return (result);
}

// узнаем максимальную степень мантисы дробного числа
static int		ft_maxPowerFractional(unsigned long	mantis)
{
	int bitIndex;
	int power;
	int bit;

	bit = 0;
	power = 0;
	bitIndex = 63;
	while (bitIndex)
	{
		bit = (mantis & (1UL << bitIndex)) != 0 ? 1 : 0;
		if (bit == 1)
		{
			power = bitIndex;
			break ;
		}
		bitIndex--;
	}
	return (power);
}	

// заполнение нулей перед числом в дробной части
static char		*ft_fillNulls(int exp, char *fraction, unsigned long mantis)
{
	int power;
	int	countNull;
	int lenFractional;
	char *result;

	lenFractional = 0;
	power = 0;
	countNull = 0;
	lenFractional = ft_strlen(fraction);
	power = ft_maxPowerFractional(mantis);
	countNull = 64 - power - exp - lenFractional;
	countNull++;
	if (countNull <= 0)
		return (NULL);
	result = (char*)malloc((countNull + 1) * sizeof(char));
	result[countNull] = '\0';
	result = ft_memset(result, '0', countNull);
	return (result);
}

// работа с мантисой
static char		*ft_workWithMantis(s_longDouble longDouble)
{
	s_powerBits					bitsPower;
	int 						numOfIntBits;
	s_arrayInt					arrayInt;
	s_doubleToChar				doubleChar;
	char 						*result;

	numOfIntBits = longDouble.exp - LDBL_MAX_EXP + 2;
	bitsPower.power = numOfIntBits;
	arrayInt = ft_findingIntPower(longDouble, numOfIntBits, bitsPower);
	doubleChar.intToChar = ft_numToChar(arrayInt);
	arrayInt = ft_findingFractionPower(longDouble, numOfIntBits, bitsPower);
	doubleChar.fractionToChar = ft_numToChar(arrayInt);
	if (numOfIntBits < 0)
		doubleChar.nulls = ft_fillNulls(numOfIntBits, doubleChar.fractionToChar, longDouble.mantis);
	result = ft_strjoin(*doubleChar.intToChar ? doubleChar.intToChar : "0", ".");
	if (doubleChar.nulls)
		result = ft_strjoin(result, doubleChar.nulls);
	result = ft_strjoin(result, *doubleChar.fractionToChar ? doubleChar.fractionToChar : "0");
	return (result);
}

// округление
static char		*ft_rounding(char *result, long long accuracy)
{
	int	check;
	char *tmp;
	long long accuracy_tmp;

	check = 0;
	tmp = result;
	accuracy_tmp = accuracy;
	while (*tmp++)
		accuracy_tmp--;
	if (accuracy_tmp <= 0)
	{
		check = result[accuracy] - '0';
		if (check > 4)
		{
			while (accuracy)
			{
				accuracy--;
				check = result[accuracy] - '0';
				check++;
				if (check > 9)
				{
					result[accuracy] = 0 + '0';
					check = result[accuracy] - '0';
				}
				else if (check != 9)
				{	
					result[accuracy] = check + '0';
					break ;
				}
			}
		}
	}
	return (result);
}

// вывод результата на экран
static void		ft_printLongDouble(char *result, long long accuracy, int sign)
{
	int		count;

	count = 0;
	if (sign == 1)
		write(1, "-", 1);
	while (*result != '.')
	{
		write(1, result, 1);
		result++;
	}
	if (accuracy == 0)
		return ;
	else
	{
		write(1, result, 1);
		result++;
		result = ft_rounding(result, accuracy);
		while (*result && accuracy--)
		{
			write(1, result, 1);
			result++;
		}
		while (accuracy-- > 0)
			write(1, "0", 1);
	}
}

// тут начинается магия
void    ft_longDouble(long double number, long long accuracy)
{
	longDoubleToUnsignedLong	bits;
	s_longDouble 				longDouble;
	char 						*result;

	bits.longDouble = number;
	if (accuracy < 0)
		return ;
	longDouble.sign = (*(&bits.unsignedLong + 1)) & (1 << 15) ? 1 : 0;
	longDouble.exp = (int)(*(&bits.unsignedLong + 1) & 0x7fffL);
	longDouble.mantis = bits.unsignedLong;
	// ft_printBitsUnsignedLong(longDouble.mantis);
	result = ft_workWithMantis(longDouble);
	ft_printLongDouble(result, accuracy, longDouble.sign);
	free(result);
}
// не забудь free