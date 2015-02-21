template <class T> void HML_MatrixMinusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция вычитает две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VHML_ResultMatrix - разница матриц;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j]-b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMinusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M)
{
/*
Функция вычитает два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VHML_ResultMatrix - первая матрица (в ней и сохраняется разница);
 b - вторая матрица;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]-=b[i][j];
}