template <class T> int TMHL_NumberOfMaximumOfVector(T *a, int VMHL_N)
{
/*
Функция ищет номер максимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер максимального элемента.
*/
T Max;
Max=a[0];
int VMHL_Result=0;
for (int i=1;i<VMHL_N;i++)
 if (a[i]>Max)
  {
  Max=a[i];
  VMHL_Result=i;
  }
return VMHL_Result;
}