void HML_NormalizationVectorAll(double *x,int VHML_N)
{
/*
Нормировка вектора чисел в отрезок [0;1] посредством функции HML_NormalizationNumberAll.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 x[i]=HML_NormalizationNumberAll(x[i]);
}