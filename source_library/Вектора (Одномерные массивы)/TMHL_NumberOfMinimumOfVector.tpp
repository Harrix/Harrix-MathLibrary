template <class T> int TMHL_NumberOfMinimumOfVector(T *a, int VMHL_N)
{
/*
Функция ищет номер минимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер минимального элемента.
*/
T Min;
Min=a[0];
int VMHL_Result=0;
for (int i=1;i<VMHL_N;i++)
 if (a[i]<Min)
  {
  Min=a[i];
  VMHL_Result=i;
  }
return VMHL_Result;
}