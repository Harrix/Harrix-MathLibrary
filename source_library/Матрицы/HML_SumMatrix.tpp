template <class T> T HML_SumMatrix(T **a,int VHML_N,int VHML_M)
{
/*
Функция вычисляет сумму элементов матрицы.
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - размер массива a (число строк);
 VHML_M - размер массива a (число столбцов).
Возвращаемое значение:
 Сумма элементов матрицы.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_Result+=a[i][j];
  
return VHML_Result;
}