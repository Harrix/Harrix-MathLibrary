template <class T> void HML_DeleteRowInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M)
{
/*
Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу.
Последняя строка зануляется.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемой строки;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=k;i<VHML_N-1;i++)
 for (j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=VHML_ResultMatrix[i+1][j];
for (j=0;j<VHML_M;j++)
 VHML_ResultMatrix[VHML_N-1][j]=0;//зануляем
}