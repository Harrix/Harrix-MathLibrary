void MHL_NormalizationVectorAll(double *x,int VMHL_N)
{
/*
Нормировка вектора чисел в отрезок [0;1] посредством функции MHL_NormalizationNumberAll.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 x[i]=MHL_NormalizationNumberAll(x[i]);
}