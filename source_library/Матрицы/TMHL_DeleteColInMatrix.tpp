template <class T> void TMHL_DeleteColInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M)
{
/*
Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы
сдвигаются влево  на единицу. Последний столбец зануляется.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемого столбца;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VMHL_N;i++)
 for (j=k;j<VMHL_M-1;j++)
  VMHL_ResultMatrix[i][j]=VMHL_ResultMatrix[i][j+1];
for (i=0;i<VMHL_N;i++)
 VMHL_ResultMatrix[i][VMHL_M-1]=0;//зануляем
}