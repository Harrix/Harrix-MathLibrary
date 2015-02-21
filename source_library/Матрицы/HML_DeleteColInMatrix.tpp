template <class T> void HML_DeleteColInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M)
{
/*
Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы
сдвигаются влево  на единицу. Последний столбец зануляется.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемого столбца;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VHML_N;i++)
 for (j=k;j<VHML_M-1;j++)
  VHML_ResultMatrix[i][j]=VHML_ResultMatrix[i][j+1];
for (i=0;i<VHML_N;i++)
 VHML_ResultMatrix[i][VHML_M-1]=0;//зануляем
}