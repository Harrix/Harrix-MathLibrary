template <class T> void HML_MatrixMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция перемножает матрицы.
Входные параметры:
 a - первый сомножитель, VHML_N x VHML_M;
 b - второй сомножитель, VHML_M x VHML_S;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число строк в матрице a;
 VHML_M - число столбцов в матрице a и строк в матрице b;
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
  for (j=0;j<VHML_M;j++) w+=a[i][j]*b[j][k];
  VHML_ResultMatrix[i][k]=w;
  }
}