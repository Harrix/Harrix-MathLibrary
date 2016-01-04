void HML_SeedRandom(void)
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
HML_Dummy=(unsigned)time(NULL);
srand(HML_Dummy);//Стандартная инициализация
rand();//первый вызов для контроля

//MersenneTwisterRandomNumberGenerator
//Инициализатор генератора случайных чисел Mersenne Twister
//В качестве начального значения для ГСЧ используем текущее время
//Инициализациz происходит еще при подключении данного файла

//Назначаем генератор по умолчанию как Mersenne Twister
HML_TypeOfRandomNumberGenerator = MersenneTwisterRandomNumberGenerator;
}
//---------------------------------------------------------------------------
double HML_RandomNumber(void)
{
/*
Генератор случайных чисел (ГСЧ).
Есть два варианта генератора случайных чисел, который можно переключать
функцией HML_SetRandomNumberGenerator.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Случайное вещественное число из интервала (0;1) или [0;1) по равномерному закону распределения.
*/
    if (HML_TypeOfRandomNumberGenerator==StandardRandomNumberGenerator)
        return (double)rand()/(RAND_MAX+1);
    if (HML_TypeOfRandomNumberGenerator==MersenneTwisterRandomNumberGenerator)
        return drand();

    return 0;
}
//---------------------------------------------------------------------------

void HML_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T)
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
    HML_TypeOfRandomNumberGenerator = T;
}
//---------------------------------------------------------------------------