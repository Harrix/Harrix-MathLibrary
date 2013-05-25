template <class T> void TMHL_MatrixToMatrix(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция копирует содержимое матрицы (двумерного массива) a в массив VMHL_ResultMatrix.
Входные параметры:
 a - указатель на исходный массив;
 VMHL_ResultMatrix - указатель на массив в который производится запись;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=a[i][j];
}