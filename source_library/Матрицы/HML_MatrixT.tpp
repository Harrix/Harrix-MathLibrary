template <class T> void HML_MatrixT(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция транспонирует матрицу.
Входные параметры:
 a - исходная матрица, (VHML_N x VHML_M);
 VHML_ResultMatrix - транспонированная матрица, (VHML_M x VHML_N);
 VHML_N - размер матрицы (число строк) в матрице a;
 VHML_M - размер матрицы (число столбцов) в матрице a.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[j][i]=a[i][j];
}