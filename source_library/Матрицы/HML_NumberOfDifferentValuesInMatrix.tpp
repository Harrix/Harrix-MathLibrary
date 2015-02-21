template <class T> int HML_NumberOfDifferentValuesInMatrix(T **a, int VHML_N, int VHML_M)
{
/*
Функция подсчитывает число различных значений в матрице.
Входные параметры:
 a - указатель на матрица;
 VHML_N - размер массива a (строки);
 VHML_M - размер массива a (столбцы).
Возвращаемое значение:
 Число различных значений в матрице.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VHML_N*VHML_M];
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  if (HML_CheckElementInVector(b,VHML_Result,a[i][j])==-1)
   {
   b[VHML_Result]=a[i][j];
   VHML_Result++;
   }
delete [] b;
return VHML_Result;
}