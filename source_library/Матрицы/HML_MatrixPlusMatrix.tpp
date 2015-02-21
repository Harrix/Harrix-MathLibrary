template <class T> void HML_MatrixPlusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция суммирует две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VHML_ResultMatrix - сумма матриц;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j]+b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixPlusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M)
{
/*
Функция суммирует два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VHML_ResultMatrix - первая матрица (в ней и сохраняется сумма);
 b - вторая матрица;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]+=b[i][j];
}