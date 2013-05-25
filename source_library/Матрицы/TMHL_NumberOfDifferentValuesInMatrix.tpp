template <class T> int TMHL_NumberOfDifferentValuesInMatrix(T **a, int VMHL_N, int VMHL_M)
{
/*
Функция подсчитывает число различных значений в матрице.
Входные параметры:
 a - указатель на матрица;
 VMHL_N - размер массива a (строки);
 VMHL_M - размер массива a (столбцы).
Возвращаемое значение:
 Число различных значений в матрице.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VMHL_N*VMHL_M];
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  if (TMHL_CheckElementInVector(b,VMHL_Result,a[i][j])==-1)
   {
   b[VMHL_Result]=a[i][j];
   VMHL_Result++;
   }
delete [] b;
return VMHL_Result;
}