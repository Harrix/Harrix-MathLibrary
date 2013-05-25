template <class T> T TMHL_MinimumOfMatrix(T **a, int VMHL_N, int VMHL_M)
{
/*
Функция ищет минимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Минимальный элемент.
*/
T VMHL_Result;
VMHL_Result=a[0][0];
for (int i=1;i<VMHL_N;i++)
 for (int j=1;j<VMHL_M;j++)
  if (a[i][j]<VMHL_Result) VMHL_Result=a[i][j];
  
return VMHL_Result;
}