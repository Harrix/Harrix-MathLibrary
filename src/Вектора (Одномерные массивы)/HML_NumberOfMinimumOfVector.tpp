template <class T> int HML_NumberOfMinimumOfVector(T *a, int VHML_N)
{
/*
Функция ищет номер минимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер минимального элемента.
*/
T Min;
Min=a[0];
int VHML_Result=0;
for (int i=1;i<VHML_N;i++)
 if (a[i]<Min)
  {
  Min=a[i];
  VHML_Result=i;
  }
return VHML_Result;
}