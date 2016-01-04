template <class T> void HML_ZeroMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M)
{
/*
Функция зануляет матрицу.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=0;//зануляем
}