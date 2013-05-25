template <class T> void TMHL_MatrixT(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция транспонирует матрицу.
Входные параметры:
 a - исходная матрица, (VMHL_N x VMHL_M);
 VMHL_ResultMatrix - транспонированная матрица, (VMHL_M x VMHL_N);
 VMHL_N - размер матрицы (число строк) в матрице a;
 VMHL_M - размер матрицы (число столбцов) в матрице a.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[j][i]=a[i][j];
}