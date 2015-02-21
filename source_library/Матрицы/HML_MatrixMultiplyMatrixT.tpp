template <class T> void HML_MatrixMultiplyMatrixT(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция умножает матрицу на транспонированную матрицу.
Входные параметры:
 a - первый сомножитель, VHML_N x VHML_M;
 b - второй сомножитель (матрица, которую мы транспонируем), VHML_S x VHML_M;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число строк в матрице a;
 VHML_M - число столбцов в матрице a и столбцов в матрице b;
 VHML_S - число строк в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VHML_N;i++)
 for (k=0;k<VHML_S;k++)
  {
  w=0;
  for (j=0;j<VHML_M;j++) w=w+a[i][j]*b[k][j];
  VHML_ResultMatrix[i][k]=w;
  }
}