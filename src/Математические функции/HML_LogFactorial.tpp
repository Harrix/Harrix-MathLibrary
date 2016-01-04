template <class T> T HML_LogFactorial(T x)
{
/*
Функция вычисляет логарифм факториала числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Логарифм факториала числа.
*/
    if (x<1) x=1;
    T S = log(1.);

    for (int i=1;i<=x;i++)
      S += log((double) i);

    return S;
}