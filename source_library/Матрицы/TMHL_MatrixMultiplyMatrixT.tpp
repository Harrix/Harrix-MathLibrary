template <class T> void TMHL_MatrixMultiplyMatrixT(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S)
{
/*
Функция умножает матрицу на транспонированную матрицу.
Входные параметры:
 a - первый сомножитель, VMHL_N x VMHL_M;
 b - второй сомножитель (матрица, которую мы транспонируем), VMHL_S x VMHL_M;
 VMHL_ResultMatrix - произведение матриц (сюда записывается результат), VMHL_N x VMHL_S;
 VMHL_N - число строк в матрице a;
 VMHL_M - число столбцов в матрице a и столбцов в матрице b;
 VMHL_S - число строк в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VMHL_N;i++)
 for (k=0;k<VMHL_S;k++)
  {
  w=0;
  for (j=0;j<VMHL_M;j++) w=w+a[i][j]*b[k][j];
  VMHL_ResultMatrix[i][k]=w;
  }
}