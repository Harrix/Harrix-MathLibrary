template <class T> int HML_NumberOfDifferentValuesInVector(T *a, int VHML_N)
{
/*
Функция подсчитывает число различных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор;
 VHML_N - размер массива a.
Возвращаемое значение:
 Число различных значений в векторе.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VHML_N];
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 if (HML_CheckElementInVector(b,VHML_Result,a[i])==-1)
  {
  b[VHML_Result]=a[i];
  VHML_Result++;
  }
delete [] b;
return VHML_Result;
}