template <class T> void TMHL_DeleteRowInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M)
{
/*
Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу.
Последняя строка зануляется.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемой строки;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=k;i<VMHL_N-1;i++)
 for (j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=VMHL_ResultMatrix[i+1][j];
for (j=0;j<VMHL_M;j++)
 VMHL_ResultMatrix[VMHL_N-1][j]=0;//зануляем
}