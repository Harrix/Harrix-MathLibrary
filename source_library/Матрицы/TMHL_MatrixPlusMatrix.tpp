template <class T> void TMHL_MatrixPlusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция суммирует две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VMHL_ResultMatrix - сумма матриц;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=a[i][j]+b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixPlusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M)
{
/*
Функция суммирует два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VMHL_ResultMatrix - первая матрица (в ней и сохраняется сумма);
 b - вторая матрица;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]+=b[i][j];
}