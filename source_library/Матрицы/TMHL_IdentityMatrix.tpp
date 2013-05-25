template <class T> void TMHL_IdentityMatrix(T **VMHL_ResultMatrix,int VMHL_N)
{
/*
Функция формирует единичную квадратную матрицу.
Входные параметры:
 VMHL_ResultMatrix - исходная матрица (в ней и сохраняется результат);
 VMHL_N - размер матрицы (число строк и столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_N;j++)
  {
  if (i==j)
   VMHL_ResultMatrix[i][j]=1;
  else
   VMHL_ResultMatrix[i][j]=0;
  }
}