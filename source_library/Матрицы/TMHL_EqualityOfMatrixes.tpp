template <class T> bool TMHL_EqualityOfMatrixes (T **a, T **b,int VMHL_N,int VMHL_M)
{
/*
Функция проверяет равенство матриц.
Входные параметры:
 a - указатель на первую матрицу;
 b - указатель на вторую матрицу;
 VMHL_N - размер массива a (число строк);
 VMHL_M - размер массива a (число столбцов).
Возвращаемое значение:
 true - матрицы совпадают;
 false - матрицы не совпадают.
*/
bool VMHL_Result=true;

for (int i=0;i<VMHL_N;i++)
    for (int j=0;j<VMHL_M;j++)
        if (a[i][j]!=b[i][j])
            VMHL_Result=false;

return VMHL_Result;
}