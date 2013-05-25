template <class T> void TMHL_RandomIntMatrixInElements(T **VMHL_ResultMatrix, T **n, T **m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом каждый элемент изменяется в своих пределах.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения каждого элемента (размер VMHL_N x VMHL_M);
 m - правые границы интервала изменения каждого элемента (размер VMHL_N x VMHL_M);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n[i][j],m[i][j]);
}