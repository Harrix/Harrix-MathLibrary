void HML_RandomRealMatrixInCols(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала.
При этом элементы каждого столбца изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левые границы интервала изменения элементов столбцов (размер VHML_M);
 Right - правые границы интервала изменения элементов столбцов (размер VHML_M);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniform(Left[j],Right[j]);
}