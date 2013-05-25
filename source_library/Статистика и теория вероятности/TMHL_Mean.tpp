template <class T> T TMHL_Mean(T *x, int VMHL_N)
{
/*
Функция вычисляет среднее арифметическое массива.
Входные параметры:
 x - массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Среднее арифметическое массива.
*/
return TMHL_SumVector(x,VMHL_N)/double(VMHL_N);
}