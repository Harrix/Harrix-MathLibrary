template <class T> T TMHL_Variance(T *x, int VMHL_N)
{
/*
Функция вычисляет выборочную дисперсию выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VMHL_N - размер массива.
Возвращаемое значение:
 Выборочная дисперсия выборки.
*/
return TMHL_SampleCovariance(x,x,VMHL_N);
}