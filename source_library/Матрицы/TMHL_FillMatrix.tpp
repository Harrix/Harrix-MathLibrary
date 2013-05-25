template <class T> void TMHL_FillMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T x)
{
/*
Функция заполняет матрицу значениями, равных x.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=x;
}