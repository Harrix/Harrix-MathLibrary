void MHL_RandomRealMatrix(double **VMHL_ResultMatrix, double Left, double Right, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    for (int j=0;j<VMHL_M;j++)
        VMHL_ResultMatrix[i][j]=MHL_RandomUniform(Left,Right);
}