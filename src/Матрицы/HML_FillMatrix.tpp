template <class T> void HML_FillMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T x)
{
/*
Функция заполняет матрицу значениями, равных x.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=x;
}