template <class T> void HML_MatrixToMatrix(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция копирует содержимое матрицы (двумерного массива) a в массив VHML_ResultMatrix.
Входные параметры:
 a - указатель на исходный массив;
 VHML_ResultMatrix - указатель на массив в который производится запись;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j];
}