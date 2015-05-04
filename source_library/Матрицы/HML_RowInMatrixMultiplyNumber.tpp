template <class T> void HML_RowInMatrixMultiplyNumber(T **VHML_ResultMatrix, int k, int VHML_M, T Number)
{
/*
Функция умножает строку матрицы на число.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 k - номер строки, которую умножают на число;
 VHML_M - размер матрицы (число столбцов);
 Number - число, на которое умножается строка матрицы.
Возвращаемое значение:
 Отсутствует.
*/
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[k][j]*=Number;
}