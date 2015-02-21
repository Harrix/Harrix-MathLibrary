template <class T> bool HML_EqualityOfMatrixes (T **a, T **b,int VHML_N,int VHML_M)
{
/*
Функция проверяет равенство матриц.
Входные параметры:
 a - указатель на первую матрицу;
 b - указатель на вторую матрицу;
 VHML_N - размер массива a (число строк);
 VHML_M - размер массива a (число столбцов).
Возвращаемое значение:
 true - матрицы совпадают;
 false - матрицы не совпадают.
*/
bool VHML_Result=true;

for (int i=0;i<VHML_N;i++)
    for (int j=0;j<VHML_M;j++)
        if (a[i][j]!=b[i][j])
            VHML_Result=false;

return VHML_Result;
}