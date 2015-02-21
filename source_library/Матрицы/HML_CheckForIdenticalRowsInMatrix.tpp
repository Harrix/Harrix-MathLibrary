template <class T> bool HML_CheckForIdenticalRowsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
    /*
Функция проверяет наличие одинаковых строк в матрице.
Входные параметры:
 VHML_ResultMatrix - указатель на массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые строки;
 false - если таких строк нет.
*/
    bool VHML_Result=false;
    bool b;
    for (int i=0;i<VHML_N;i++)
        for (int ii=0;ii<VHML_N;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VHML_M;j++)
            {
                if (VHML_ResultMatrix[i][j]!=VHML_ResultMatrix[ii][j]) b=false;
            }
            if (b) VHML_Result=true;
            }
        }
    return VHML_Result;
}