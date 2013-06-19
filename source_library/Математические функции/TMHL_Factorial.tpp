template <class T> T TMHL_Factorial(T x)
{
/*
Функция вычисляет факториал числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Факториал числа.
*/
    if (x<1) x=1;
    T S=1;
    for (int i=0; i<x; i++)
        S*=i+1;

    return S;
}