template <class T> void HML_MatrixTMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция умножает транспонированную матрицу на матрицу.
Входные параметры:
 a - первый сомножитель (матрица, которую мы транспонируем), VHML_M x VHML_N;
 b - второй сомножитель, VHML_M x VHML_S;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число столбцов в матрице a;
 VHML_M - число строк в матрице a и строк в матрице b;
 VHML_S - число столбцов в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VHML_N;i++)
 for (k=0;k<VHML_S;k++)
  {
  w=0;
  for (j=0;j<VHML_M;j++) w=w+a[j][i]*b[j][k];
  VHML_ResultMatrix[i][k]=w;
  }
}