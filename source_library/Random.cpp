void MHL_SeedRandom(void)
{
/*
Инициализатор генератора случайных чисел.
В данном случае используется самый простой его вариант со всеми его недостатками.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Отсутствуют.
*/
//StandardRandomNumberGenerator
//Инициализатор стандартного генератора случайных чисел
//В качестве начального значения для ГСЧ используем текущее время
MHL_Dummy=(unsigned)time(NULL);
srand(MHL_Dummy);//Стандартная инициализация
//rand();//первый вызов для контроля

//MersenneTwisterRandomNumberGenerator
//Инициализатор генератора случайных чисел Mersenne Twister
//В качестве начального значения для ГСЧ используем текущее время
//Инициализациz происходит еще при подключении данного файла

//Назначаем генератор по умолчанию как Mersenne Twister
MHL_TypeOfRandomNumberGenerator = MersenneTwisterRandomNumberGenerator;
}
//---------------------------------------------------------------------------
double MHL_RandomNumber(void)
{
/*
Генератор случайных чисел (ГСЧ).
Есть два варианта генератора случайных чисел, который можно переключать
функцией MHL_SetRandomNumberGenerator.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Случайное вещественное число из интервала (0;1) или [0;1) по равномерному закону распределения.
*/
    if (MHL_TypeOfRandomNumberGenerator==StandardRandomNumberGenerator)
        return (double)rand()/(RAND_MAX+1);
    if (MHL_TypeOfRandomNumberGenerator==MersenneTwisterRandomNumberGenerator)
        return drand();

    return 0;
}
//---------------------------------------------------------------------------

void MHL_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T)
{
/*
Функция переназначает генератор случайных чисел.
Входные параметры:
 TypeOfRandomNumberGenerator - тип генератора случайных чисел:
  StandardRandomNumberGenerator - стандартный генератор случайных чисел;
  MersenneTwisterRandomNumberGenerator - генератор случайных чисел Mersenne Twister.
Возвращаемое значение:
 Отсутствует.
*/
    MHL_TypeOfRandomNumberGenerator = T;
}
//---------------------------------------------------------------------------