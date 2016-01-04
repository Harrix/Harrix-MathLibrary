void HML_RandomRealMatrixInRows(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала.
При этом элементы каждой строки изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левые границы интервала изменения элементов строки (размер VHML_N);
 Right - правые границы интервала изменения элементов строки (размер VHML_N);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniform(Left[i],Right[i]);
}