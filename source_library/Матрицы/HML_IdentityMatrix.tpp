template <class T> void HML_IdentityMatrix(T **VHML_ResultMatrix,int VHML_N)
{
/*
Функция формирует единичную квадратную матрицу.
Входные параметры:
 VHML_ResultMatrix - исходная матрица (в ней и сохраняется результат);
 VHML_N - размер матрицы (число строк и столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_N;j++)
  {
  if (i==j)
   VHML_ResultMatrix[i][j]=1;
  else
   VHML_ResultMatrix[i][j]=0;
  }
}