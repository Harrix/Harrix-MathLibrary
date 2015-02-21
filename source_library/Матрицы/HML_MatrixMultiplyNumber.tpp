template <class T> void HML_MatrixMultiplyNumber(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T Number)
{
/*
Функция умножает матрицу на число.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_N - размер матрицы (число строк);
 VHML_M - размер матрицы (число столбцов);
 Number - число, на которое умножается матрица.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]*=Number;
}