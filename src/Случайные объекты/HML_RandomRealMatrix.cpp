void HML_RandomRealMatrix(double **VHML_ResultMatrix, double Left, double Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    for (int j=0;j<VHML_M;j++)
        VHML_ResultMatrix[i][j]=HML_RandomUniform(Left,Right);
}