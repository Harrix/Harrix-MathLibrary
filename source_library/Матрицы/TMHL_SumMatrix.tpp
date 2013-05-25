template <class T> T TMHL_SumMatrix(T **a,int VMHL_N,int VMHL_M)
{
/*
Функция вычисляет сумму элементов матрицы.
Входные параметры:
 a - указатель на исходный массив;
 VMHL_N - размер массива a (число строк);
 VMHL_M - размер массива a (число столбцов).
Возвращаемое значение:
 Сумма элементов матрицы.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_Result+=a[i][j];
  
return VMHL_Result;
}