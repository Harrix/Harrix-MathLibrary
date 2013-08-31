template <class T> bool TMHL_CheckForIdenticalColsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
    /*
Функция проверяет наличие одинаковых столбцов в матрице.
Входные параметры:
 VMHL_ResultMatrix - указатель на массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые столбцы;
 false - если таких столбцы нет.
*/
    bool VMHL_Result=false;
    bool b;
    for (int i=0;i<VMHL_M;i++)
        for (int ii=0;ii<VMHL_M;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VMHL_N;j++)
            {
                if (VMHL_ResultMatrix[j][i]!=VMHL_ResultMatrix[j][ii]) b=false;
            }
            if (b) VMHL_Result=true;
            }
        }
    return VMHL_Result;
}