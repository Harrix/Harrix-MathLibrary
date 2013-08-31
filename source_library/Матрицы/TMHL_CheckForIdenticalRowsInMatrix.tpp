template <class T> bool TMHL_CheckForIdenticalRowsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
    /*
Функция проверяет наличие одинаковых строк в матрице.
Входные параметры:
 VMHL_ResultMatrix - указатель на массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые строки;
 false - если таких строк нет.
*/
    bool VMHL_Result=false;
    bool b;
    for (int i=0;i<VMHL_N;i++)
        for (int ii=0;ii<VMHL_N;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VMHL_M;j++)
            {
                if (VMHL_ResultMatrix[i][j]!=VMHL_ResultMatrix[ii][j]) b=false;
            }
            if (b) VMHL_Result=true;
            }
        }
    return VMHL_Result;
}