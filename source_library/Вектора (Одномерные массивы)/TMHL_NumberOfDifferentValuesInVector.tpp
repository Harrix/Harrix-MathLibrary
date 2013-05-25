template <class T> int TMHL_NumberOfDifferentValuesInVector(T *a, int VMHL_N)
{
/*
Функция подсчитывает число различных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор;
 VMHL_N - размер массива a.
Возвращаемое значение:
 Число различных значений в векторе.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VMHL_N];
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 if (TMHL_CheckElementInVector(b,VMHL_Result,a[i])==-1)
  {
  b[VMHL_Result]=a[i];
  VMHL_Result++;
  }
delete [] b;
return VMHL_Result;
}