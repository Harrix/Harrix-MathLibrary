template <class T> void HML_ColInMatrixMultiplyNumber(T **VHML_ResultMatrix, int k, int VHML_N, T Number)
{
/*
Функция умножает столбец матрицы на число.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 k - номер столбца, который умножают на число;
 VHML_N - размер матрицы (число строк);
 Number - число, на которое умножается столбец матрицы.
Возвращаемое значение:
 Отсутствует.
*/
 for (int i=0;i<VHML_N;i++)
  VHML_ResultMatrix[i][k]*=Number;
}