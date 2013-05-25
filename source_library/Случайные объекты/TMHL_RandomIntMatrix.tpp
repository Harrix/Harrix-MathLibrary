template <class T> void TMHL_RandomIntMatrix(T **VMHL_ResultMatrix, T n, T m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левая граница интервала;
 m - правая граница интервала;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n,m);
}