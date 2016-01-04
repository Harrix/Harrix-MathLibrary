template <class T> T HML_MaximumOfMatrix(T **a, int VHML_N, int VHML_M)
{
/*
Функция ищет максимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Максимальный элемент.
*/
T VHML_Result;
VHML_Result=a[0][0];
for (int i=1;i<VHML_N;i++)
 for (int j=1;j<VHML_M;j++)
  if (a[i][j]>VHML_Result) VHML_Result=a[i][j];
  
return VHML_Result;
}