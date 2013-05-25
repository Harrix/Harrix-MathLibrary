template <class T> void TMHL_MatrixMultiplyNumber(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T Number)
{
/*
Функция умножает матрицу на число.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_N - размер матрицы (число строк);
 VMHL_M - размер матрицы (число столбцов);
 Number - число, на которое умножается матрица.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]*=Number;
}